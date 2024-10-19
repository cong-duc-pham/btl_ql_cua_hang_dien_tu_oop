#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class NhanVien {
    protected:
        static int IDNV;
        static int IDQL;
        string maNV;
        string hoTen;
        string namSinh;
        string chucVu;
        string pass;
        long long mucLuong;
    public:
        virtual void nhapThongTin();  
        virtual void setChucVuVaLuong() = 0; 
        virtual ~NhanVien() {}
        friend ostream& operator << (ostream& out, NhanVien& a);
        string getMaNV();
        string getPass();
        string getChucVu();
        string getHoTen();

};
class HangHoa{
    private:
        static int maHH;
        string IDHH;
        int soLuong;
        string nameSP;
        long long giaSP;
        string loaiSP;
    public:
        virtual void nhapThongTinSP();
        friend ostream& operator << (ostream& out, HangHoa a);
        string getNameSP();
        long long getGiaSP();
        string getLoaiSP();
        string getIDHH();
        int getSoLuong();
        void setLoaiSP(string loai);
};


// Khởi tạo biến static
int NhanVien::IDNV = 0;

int NhanVien::IDQL = 0;

int HangHoa ::maHH = 0;

void HangHoa::setLoaiSP(string loai) {
    loaiSP = loai;
}

void HangHoa::nhapThongTinSP(){
    cout << "Nhap ten hang hoa: "; 
    cin.ignore();
    getline(cin, nameSP);
    cout << "Nhap so luong hang nhap ve: ";
    cin >> soLuong;
    cout << "Nhap gia thanh: ";
    cin >> giaSP;
    ++maHH;
    stringstream ss;
    ss << "HH" << setw(3) << setfill('0') << maHH;  
    IDHH = ss.str();  // Gán ID cho sản phẩm
}

void NhanVien::nhapThongTin() {

    cout << "Nhap ho ten nhan vien: "; cin.ignore();
    getline(cin, hoTen);
    cout << "Nhap mat khau: ";
    cin >> pass;
    cout << "Nhap nam sinh: ";
    cin >> namSinh;
}

ostream& operator << (ostream& out, NhanVien& a) {
    out << a.maNV << "\t" << a.hoTen << "\t" << a.namSinh << "\t" << a.chucVu << "\t" << a.mucLuong << endl;
    return out;
}

string HangHoa::getNameSP() {
    return nameSP;
}

long long HangHoa::getGiaSP() {
    return giaSP;
}

string HangHoa::getLoaiSP() {
    return loaiSP;
}

string HangHoa::getIDHH() {
    return IDHH;
}

int HangHoa::getSoLuong() {
    return soLuong;
}

string NhanVien::getMaNV() {
    return maNV;
}

string NhanVien::getPass() {
    return pass;
}
string NhanVien::getHoTen() {
    return hoTen;
}
string NhanVien::getChucVu() {
    return chucVu;
}
// Các lớp kế thừa từ NhanVien

class LeTan : public NhanVien {
public:
    void setChucVuVaLuong() override {
        chucVu = "Le tan";
        mucLuong = 2000000;
        ++IDNV;
        stringstream ss;
        ss << "NV" << setw(3) << setfill('0') << IDNV;  
        maNV = ss.str();
    }
};

class ThuNgan : public NhanVien {
public:
    void setChucVuVaLuong() override {
        chucVu = "Thu ngan";
        mucLuong = 4000000;
        ++IDNV;
        stringstream ss;
        ss << "NV" << setw(3) << setfill('0') << IDNV;  
        maNV = ss.str();
    }
};

class BanHang : public NhanVien {
public:
    void setChucVuVaLuong() override {
        chucVu = "Ban hang";
        mucLuong = 12000000;
        ++IDNV;
        stringstream ss;
        ss << "NV" << setw(3) << setfill('0') << IDNV;  
        maNV = ss.str();
    }
};

class KyThuat : public NhanVien {
public:
    void setChucVuVaLuong() override {
        chucVu = "Ky thuat";
        mucLuong = 20000000;
        ++IDNV;
        stringstream ss;
        ss << "NV" << setw(3) << setfill('0') << IDNV;
        maNV = ss.str();
    }
};

class BaoTri : public NhanVien {
public:
    void setChucVuVaLuong() override {
        chucVu = "Bao tri";
        mucLuong = 20000000;
        ++IDNV;
        stringstream ss;
        ss << "NV" << setw(3) << setfill('0') << IDNV;  
        maNV = ss.str();
    }
};

class QuanLy : public NhanVien {
public:
    void setChucVuVaLuong() override {
        chucVu = "Quan ly";
        mucLuong = 30000000;
        ++IDQL;  // Tăng ID quản lý
        stringstream ss;
        ss << "QL" << setw(3) << setfill('0') << IDQL;  // Định dạng thành "QL" + 3 chữ số
        maNV = ss.str();
    }
};

// Cấu trúc danh sách liên kết đơn cho nhân viên
struct node {
    NhanVien* info;
    node* next;
};

struct List {
    node* phead, * ptail;
};

void init(List& L) {
    L.phead = L.ptail = NULL;
}

node* createNode(NhanVien* nv) {
    node* p = new node;
    p->info = nv;
    p->next = NULL;
    return p;
}

void addTail(List& l, NhanVien* nv) {
    node* p = createNode(nv);
    if (l.phead == NULL) {
        l.phead = l.ptail = p;
    } else {
        l.ptail->next = p;
        l.ptail = p;
    }
}

void printList(List l) {
    node* p = l.phead;
    while (p != NULL) {
        if (p->info->getChucVu() != "Quan ly"){
            cout << *(p->info);
        }
        p = p->next;
    }
}
// Cấu trúc danh sách liên kết đơn cho sản phẩm
struct nodeSP {
    HangHoa* info;
    nodeSP* next;
};

struct ListSP {
    nodeSP* phead, * ptail;
};

void initSP(ListSP& L) {
    L.phead = L.ptail = NULL;
}

nodeSP* createNodeSP(HangHoa* sp) {
    nodeSP* p = new nodeSP;
    p->info = sp;
    p->next = NULL;
    return p;
}

void addTailSP(ListSP& l, HangHoa* sp) {
    nodeSP* p = createNodeSP(sp);
    if (l.phead == NULL) {
        l.phead = l.ptail = p;
    } else {
        l.ptail->next = p;
        l.ptail = p;
    }
}

void printListSP(ListSP l) {
    nodeSP* p = l.phead;
    while (p != NULL) {
        cout << *(p->info);  
        p = p->next;
    }
}

  
NhanVien* checkLogin(List l, string ID, string pass){
    node* p = l.phead;
    while (p != NULL) {
        if (p->info->getMaNV() == ID && p->info->getPass() == pass) {
            return p->info;  
        }
        p = p->next;
    }
    return NULL; 
}

// Hàm tạo nhân viên dựa trên chức vụ
NhanVien* createNhanVien(int chuc) {
    NhanVien* nv;
    if (chuc == 1) nv = new LeTan();
    else if (chuc == 2) nv = new ThuNgan();
    else if (chuc == 3) nv = new BanHang();
    else if (chuc == 4) nv = new KyThuat();
    else if (chuc == 5) nv = new BaoTri();
    else nv = new QuanLy();
    nv->nhapThongTin();
    nv->setChucVuVaLuong();
    return nv;
}
HangHoa* createHangHoa(int loai) {
    HangHoa* sp = new HangHoa();
    sp->nhapThongTinSP();

    switch(loai) {
        case 1: sp->setLoaiSP("Dien Thoai di dong"); break;
        case 2: sp->setLoaiSP("Laptop-may tinh bang"); break;
        case 3: sp->setLoaiSP("Gia dung"); break;
        case 4: sp->setLoaiSP("Tu lanh"); break;
        case 5: sp->setLoaiSP("Noi dien"); break;
    }
    return sp;
}
ostream& operator << (ostream& out, HangHoa a) {
    out << a.getIDHH() << "\t" << a.getLoaiSP() << "\t" << a.getNameSP() << "\t" << a.getSoLuong() << "\t" << a.getGiaSP() << endl; 
    return out;
}

// Hàm chính
int main() {
    List dsNV;
    init(dsNV);

    List dsQL;
    init(dsQL);

    ListSP dsSP;
    initSP(dsSP);

    int login;
    do {
        cout << "**Chao mung den voi cua hang dien thoai di dong va thiet bi dien tu tieu dung DTL**\n";
        cout << "-1. Dang ky\n";
        cout << "-2. Dang nhap\n";

        cout << "Nhap lua chon cua ban: ";
        cin >> login;

        while (login < 1 || login > 2) {
            cout << "Hay chon 1 trong cac muc nay!\n";
            cout << "1. Dang ky\n";
            cout << "2. Dang nhap\n";
            cout << "Nhap lua chon cua ban: ";
            cin >> login;
        }

        if (login == 1) {
            int chuc;
            cout << "============Dang ki=============\n";
            cout << "Chuc vu cua ban la: \n";
            cout << "1. Le tan\n";
            cout << "2. Thu ngan\n";
            cout << "3. Ban hang\n";
            cout << "4. Ky thuat\n";
            cout << "5. Bao tri\n";
            cout << "6. Quan ly\n";
            cout << "Nhap lua chon cua ban: ";
            cin >> chuc;

            while (chuc < 1 || chuc > 6) {
                cout << "Hay chon 1 trong cac muc nay!\n";
                cout << "Nhap lua chon cua ban: ";
                cin >> chuc;
            }

            NhanVien* x = createNhanVien(chuc);
            addTail(dsNV, x);
            cout << "Da dang ki thanh cong!!\n";
            cout << *x;

        } else if (login == 2) {
            string ID_current, pass_current;
            cout << "============Dang Nhap===========\n";
            cout << "Nhap ID: ";
            cin.ignore();
            getline(cin, ID_current);
            cout << "Nhap mat khau: ";
            getline(cin, pass_current);

            NhanVien* user = checkLogin(dsNV, ID_current, pass_current);
            
            if (user != NULL) {
                cout << "Dang nhap thanh cong!!\n";
                cout << "Xin chao " << user->getHoTen() << "!\n"; 

                if (user->getChucVu() == "Le tan") {
                    int choose = 0;
                    cout << "Ban da dang nhap voi chuc vu Le Tan\n";
                    do{
                        cout << "=================MENU===================\n";
                        cout << "               (Le tan)                 \n";
                        cout << "1. Xem so luong khach hang hien tai\n";
                        cout << "2. Dang suat";
                        cin >> choose ;
                        switch(choose){
                            case 1:
                                //printListKH
                                break;
                            case 2:
                                cout << "Dang xuat...\n";
                                break;
                        }
                    }while(choose != 2);

                } 
                else if (user->getChucVu() == "Thu ngan") {
                    int choose = 0;
                    cout << "Ban da dang nhap voi chuc vu Thu Ngan\n";
                    do{
                        cout << "=================MENU===================\n";
                        cout << "              (Thu ngan)                \n";
                        cout << "1. Xem danh sach cac san pham ban ra\n";
                        cout << "2. Xem tong so tien thu duoc\n";
                        cout << "3. Dang suat";
                        cin >> choose;
                        switch(choose){
                            case 1:
                                //printfListHH->buyed
                                break;
                            case 2:
                                //printmoneyBuyed
                                break;
                            case 3: 
                                cout << "Dang xuat...\n";
                                break;
                        }
                    }while(choose != 3);
                }
                else if (user->getChucVu() == "Ban hang") {
                    int choose = 0;
                    cout << "Ban da dang nhap voi chuc vu Ban Hang\n";
                    do{
                        cout << "=================MENU===================\n";
                        cout << "              (Ban hang)                \n";
                        cout << "1. Xem so luong khach hang hien tai\n";
                        cout << "2. Xem so luong san pham con hang\n";
                        cout << "3. Xem so luong san pham ban ra\n";
                        cout << "4. Dang suat";
                        cin >> choose;
                        switch(choose){
                            case 1:
                                //PrintListKH;
                                break;
                            case 2:
                                cout << "ID" << "\t" << "Loai san pham" << "\t" << "Ten san pham" << "\t" << "So luong" << "\t" << "Gia" << endl; 
                                printListSP(dsSP);
                                break;
                            case 3:
                                //PrintListHHBuyed
                                break;
                            case 4:
                                cout << "Dang xuat...\n";
                                break;
                        }
                    }while(choose != 4);
                }
                else if (user->getChucVu() == "Ky thuat") {
                    int choose = 0;
                    cout << "Ban da dang nhap voi chuc vu Ky Thuat\n";
                    do{
                        cout << "=================MENU===================\n";
                        cout << "              (Ki thuat)                \n";
                        cout << "1. xem danh sach khach hang hien tai\n";
                        cout << "2. Xem danh sach san pham ban ra\n";
                        cout << "3. Xem danh sach san pham con lai"
                        cout << "4. Dang suat";
                        cin >> choose;
                        switch(choose){
                            case 1:
                                //printListKH
                                break;
                            case 2:
                                //printListSPBuyed
                                break;
                            case 3:
                                cout << "ID" << "\t" << "Loai san pham" << "\t" << "Ten san pham" << "\t" << "So luong" << "\t" << "Gia" << endl; 
                                printListSP(dsSP);
                                break;
                            case 4:
                                cout << "Dang xuat...\n";
                                break;
                        }
                    }while(choose =! 3);
                }
                else if (user->getChucVu() == "Bao tri") {
                    int choose = 0;
                    cout << "Ban da dang nhap voi chuc vu Bao Tri\n";
                    do{
                        cout << "=================MENU===================\n";
                        cout << "               (Bao tri)                \n";
                        cout << "1. xem so luong khach hang hien tai\n";
                        cout << "2. Xem so luong san pham ban ra\n";
                        cout << "3. Dang suat";
                        cin >> choose;
                        switch(choose){
                            case 1: 
                                //printListKH
                                break;
                            case 2:
                                //printlistSPBuyed
                                break;
                            case 3:
                                cout << "Dang xuat...\n";
                                break;
                        }
                    }while(choose != 3);
                }
                else {
                    int chose = 0;  
                    cout << "Ban da dang nhap voi chuc vu Quan Ly\n";
                    do {
                        
                        cout << "=================MENU===================\n";
                        cout << "               (Quan ly)                \n";
                        cout << "1. Xem so luong khach hang hien tai\n";
                        cout << "2. Xem danh sach nhan vien\n";
                        cout << "3. Xem danh sach cac mat hang con lai\n";
                        cout << "4. Xem danh sach cac mat hang duoc ban\n";
                        cout << "5. Xem tong so tien thu duoc\n";
                        cout << "6. Them mat hang\n";
                        cout << "7. Dang xuat\n"; 
                        cout << "Nhap lua chon cua ban: ";
                        cin >> chose;

                        switch(chose) {
                            case 1:
                                
                                break;
                            case 2:
                                printList(dsNV);
                                break;
                            case 3:
                                cout << "ID" << "\t" << "Loai san pham" << "\t" << "Ten san pham" << "\t" << "So luong" << "\t" << "Gia" << endl; 
                                printListSP(dsSP);
                                break;
                            case 4:
                                // Code xử lý mục 4
                                break;
                            case 5:
                                // Code xử lý mục 5
                                break;
                            case 6: {
                                cout << "Them mat hang:\n";
                                int sp;
                                cout << "Loai san pham:\n";
                                cout << "1. Dien Thoai di dong\n";
                                cout << "2. Laptop-may tinh bang\n";
                                cout << "3. Gia dung\n";
                                cout << "4. Tu lanh\n";
                                cout << "5. Noi dien\n";
                                cout << "Nhap lua chon cua ban: ";
                                cin >> sp;

                                while (sp < 1 || sp > 5) {
                                    cout << "Hay chon 1 trong cac muc nay!\n";
                                    cout << "Nhap lua chon cua ban: ";
                                    cin >> sp;
                                }

                                HangHoa* h = createHangHoa(sp); // Truyền tham số "sp" để xác định loại sản phẩm
                                addTailSP(dsSP, h);
                                cout << "Da them thanh cong!!\n";
                                break;
                            }
                            case 7:
                                cout << "Dang xuat...\n";  // Thoát khỏi vòng lặp menu quản lý để quay về menu chính
                                break;
                            default:
                                cout << "Lua chon khong hop le!\n";
                                break;
                        }
                    } while (chose != 7);  // Vòng lặp cho đến khi người dùng chọn đăng xuất
                }
            } else {
                cout << "ID hoac mat khau khong dung!\n";
            }
        }
        cout << "\nBan co muon quay lai trang chu khong? (1: Co, 0: Khong): ";
        cin >> login;
    } while (login == 1);
    system("pause");
}