#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class NhanVien {
    protected:
        static int IDNV;
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

// Khởi tạo biến static
int NhanVien::IDNV = 0;

void NhanVien::nhapThongTin() {
    ++IDNV;
    stringstream ss;
    ss << "NV" << setw(3) << setfill('0') << IDNV;  // Định dạng thành "NV" + 3 chữ số
    maNV = ss.str();
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
    }
};

class ThuNgan : public NhanVien {
public:
    void setChucVuVaLuong() override {
        chucVu = "Thu ngan";
        mucLuong = 4000000;
    }
};

class BanHang : public NhanVien {
public:
    void setChucVuVaLuong() override {
        chucVu = "Ban hang";
        mucLuong = 12000000;
    }
};

class KyThuat : public NhanVien {
public:
    void setChucVuVaLuong() override {
        chucVu = "Ky thuat";
        mucLuong = 20000000;
    }
};

class BaoTri : public NhanVien {
public:
    void setChucVuVaLuong() override {
        chucVu = "Bao tri";
        mucLuong = 20000000;
    }
};

class QuanLy : public NhanVien {
public:
    void setChucVuVaLuong() override {
        chucVu = "Quan ly";
        mucLuong = 30000000;
    }
};

// Cấu trúc danh sách liên kết đơn
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

// Khach hang 
class KhachHang {
    protected:
        static int IDKH;
        string maKH;
        string hoTenKH;
        string namSinhKH;
        string passKH;
        long long soDienThoaiKH;
    public:
        virtual void nhapThongTinKH();  
        friend ostream& operator << (ostream& out, KhachHang& a);
        string getMaKH();
        string getPassKH();
        string getHoTenKH();
        long long getsoDienThoaiKH();
};

// khoi tao bien static cho khach hang
int KhachHang::IDKH = 0;

void KhachHang::nhapThongTinKH() {
    ++IDKH;
    stringstream ss;
    ss << "KH" << setw(3) << setfill('0') << IDKH;  // Định dạng thành "KH" + 3 chữ số
    maKH = ss.str();
    cout << "Nhap ho ten khach hang: "; cin.ignore();
    getline(cin, hoTenKH);
    cout << "Nhap mat khau: ";
    cin >> passKH;
    cout << "Nhap nam sinh: ";
    cin >> namSinhKH;
    cout << "Nhap so dien thoai: ";
    cin >> soDienThoaiKH;
}

ostream &operator << (ostream &out, KhachHang &a) {
    out << a.maKH << "\t" << a.hoTenKH << "\t" << a.namSinhKH << "\t" << endl;
    return out;
}

string KhachHang::getMaKH() {
    return maKH;
}

string KhachHang::getPassKH() {
    return passKH;
}
string KhachHang::getHoTenKH() {
    return hoTenKH;
}

long long KhachHang::getsoDienThoaiKH(){
	return soDienThoaiKH;
}
struct nodeKH{
	KhachHang *info;
	nodeKH *next;
};

struct ListKH{
	nodeKH *phead, *ptail;
};

void initKH(ListKH &L){
	L.phead=L.ptail=NULL;
}

nodeKH* createNodeKH(KhachHang *kh) {
    nodeKH *p = new nodeKH;
    p->info = kh;
    p->next = NULL;
    return p;
}

void addTailKH(ListKH& l, KhachHang *kh) {
    nodeKH *p = createNodeKH(kh);
    if (l.phead == NULL) {
        l.phead = l.ptail = p;
    } else {
        l.ptail->next = p;
        l.ptail = p;
    }
}

void printListKH(ListKH l) {
    nodeKH *p = l.phead;
    while (p != NULL) {
        cout << *(p->info);
        p = p->next;
    }
}

class KhachHangThanThiet : public KhachHang {
private:
    int diemTichLuy;
public:
    KhachHangThanThiet() : diemTichLuy(0) {}

    void nhapThongTinKH() override {
        KhachHang::nhapThongTinKH();  
        cout << "Nhap diem tich luy: ";
        cin >> diemTichLuy;
    }

    int getDiemTichLuy() {
        return diemTichLuy;
    }

    friend ostream& operator << (ostream& out, KhachHangThanThiet& a) {
        out << a.maKH << "\t" << a.hoTenKH << "\t" << a.namSinhKH << "\t" 
            << a.soDienThoaiKH << "\t" << "Diem tich luy: " << a.diemTichLuy << endl;
        return out;
    }
};


// Hàm chính
int main() {
    List dsNV;
    init(dsNV);
    List dsQL;
    init(dsQL);
    int login;

    // Khach hang
    int chon; 
    List(dsKH)
    init(dsKH);
    int login;
    cout<<"  Moi xac nhan danh tinh" << endl;
	cout<<"==========================" << endl;
	cout<<"1. Nhan vien" << endl;
	cout<<"2. Khach hang" << endl;
	cout<<"Moi nhap: ";
	cin>> chon;
    
    switch(chon){
        case 1:{
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
            int loaiKH;
            cout << "============Dang ki=============\n";
            cout << "Ban muon dang ki loai khach hang nao: \n";
            cout << "1. Khach hang thuong \n";
            cout << "2. Khach hang than thiet\n";
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
                cout << "Xin chao " << user->getHoTen() << "!\n";  // Hiển thị tên người dùng
                
                // Hiển thị menu tương ứng với chức vụ
                if (user->getChucVu() == "Le tan") {
                    int choose;
                    cout << "Ban da dang nhap voi chuc vu Le Tan\n";
                    cout << "=================MENU===================\n";
                    cout << "               (Le tan)                 \n";
                    cout << "1. Xem so luong khach hang hien tai\n";
                    cout << "2. Quay lai\n";

                } 
                else if (user->getChucVu() == "Thu ngan") {
                    cout << "Ban da dang nhap voi chuc vu Thu Ngan\n";
                    cout << "=================MENU===================\n";
                    cout << "              (Thu ngan)                \n";
                    cout << "1. Xem danh sach cac san pham ban ra\n";
                    cout << "2. Xem tong so tien thu duoc\n";
                    cout << "2. Quay lai\n";
                }
                else if (user->getChucVu() == "Ban hang") {
                    cout << "Ban da dang nhap voi chuc vu Ban Hang\n";
                    cout << "=================MENU===================\n";
                    cout << "              (Ban hang)                \n";
                    cout << "1. Xem so luong khach hang hien tai\n";
                    cout << "2. Xem so luong san pham con hang\n";
                    cout << "3. Xem so luong san pham ban ra\n";
                }
                else if (user->getChucVu() == "Ky thuat") {
                    cout << "Ban da dang nhap voi chuc vu Ky Thuat\n";
                    cout << "=================MENU===================\n";
                    cout << "              (Ki thuat)                \n";
                    cout << "1. xem so luong khach hang hien tai\n";
                    cout << "2. Xem so luong san pham ban ra\n";
                    cout << "3. quay lai\n";
                }
                else if (user->getChucVu() == "Bao tri") {
                    cout << "Ban da dang nhap voi chuc vu Bao Tri\n";
                    cout << "=================MENU===================\n";
                    cout << "               (Bao tri)                \n";
                    cout << "1. xem so luong khach hang hien tai\n";
                    cout << "2. Xem so luong san pham ban ra\n";
                    cout << "3. quay lai\n";
                }
                else {
                    cout << "Ban da dang nhap voi chuc vu Quan Ly\n";
                    cout << "=================MENU===================\n";
                    cout << "               (Quan ly)                \n";
                    cout << "1. xem so luong khach hang hien tai\n";
                    cout << "2. Xem danh sach nhan vien\n";
                    cout << "3. Xem danh sach cac mat hang con lai\n";
                    cout << "4. xem danh sach cac mat hang duoc ban\n";
                    cout << "5. Xem tong so tien thu duoc\n";
                    cout << "6. quay lai\n";
                }
            } else {
                cout << "ID hoac mat khau khong dung!\n";
            }
        }
        cout << "\nBan co muon quay lai trang chu khong? (1: Co, 0: Khong): ";
        cin >> login;
    } while (login == 1);
        break;
        }

        case 2:{
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
            int loaiKH;
            cout << "============Dang ki=============\n";
            cout << "Ban muon dang ki loai khach hang nao: \n";
            cout << "1. Khach hang thuong\n";
            cout << "2. Khach hang than thiet\n";
            cout << "Nhap lua chon cua ban: ";
            cin >> loaiKH;

            while (chuc < 1 || chuc > 2) {
                cout << "Hay chon 1 trong cac muc nay!\n";
                cout << "Nhap lua chon cua ban: ";
                cin >> loaiKH;
            }

            KhachHang* x = createKhachHang(loaiKH);
            addTail(dsKH, x);
            cout << "Da dang ki thanh cong!!\n";
            cout << *x;

        } else if (login == 2) {
            string ID_current_cus, pass_current_cus;
            cout << "============Dang Nhap===========\n";
            cout << "Nhap ID: ";
            cin.ignore();
            getline(cin, ID_current_cus);
            cout << "Nhap mat khau: ";
            getline(cin, pass_current_cus);

            NhanVien* user = checkLogin(dsNV, ID_current_cus, pass_current_cus);
            
            if (user != NULL) {
                cout << "Dang nhap thanh cong!!\n";
                cout << "Xin chao " << user->getHoTen() << "!\n";  // Hiển thị tên người dùng
                
                // Hiển thị menu tương ứng với chức vụ
                if (user->getChucVu() == "Le tan") {
                    int choose;
                    cout << "Ban da dang nhap voi chuc vu Le Tan\n";
                    cout << "=================MENU===================\n";
                    cout << "               (Le tan)                 \n";
                    cout << "1. Xem so luong khach hang hien tai\n";
                    cout << "2. Quay lai\n";

                } 
                else 
                    cout << "Ban da dang nhap voi chuc vu Thu Ngan\n";
                    cout << "=================MENU===================\n";
                    cout << "              (Thu ngan)                \n";
                    cout << "1. Xem danh sach cac san pham ban ra\n";
                    cout << "2. Xem tong so tien thu duoc\n";
                    cout << "2. Quay lai\n";
                }
                else if (user->getChucVu() == "Ban hang") {
                    cout << "Ban da dang nhap voi chuc vu Ban Hang\n";
                    cout << "=================MENU===================\n";
                    cout << "              (Ban hang)                \n";
                    cout << "1. Xem so luong khach hang hien tai\n";
                    cout << "2. Xem so luong san pham con hang\n";
                    cout << "3. Xem so luong san pham ban ra\n";
                }
                else if (user->getChucVu() == "Ky thuat") {
                    cout << "Ban da dang nhap voi chuc vu Ky Thuat\n";
                    cout << "=================MENU===================\n";
                    cout << "              (Ki thuat)                \n";
                    cout << "1. xem so luong khach hang hien tai\n";
                    cout << "2. Xem so luong san pham ban ra\n";
                    cout << "3. quay lai\n";
                }
               
            } else {
                cout << "ID hoac mat khau khong dung!\n";
            }
        }
        cout << "\nBan co muon quay lai trang chu khong? (1: Co, 0: Khong): ";
        
    } while (login == 1);
        break;
        }
    }
    
    
    system("pause");
}
