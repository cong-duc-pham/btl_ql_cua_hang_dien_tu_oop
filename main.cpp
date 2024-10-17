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

// Hàm chính
int main() {
    List dsNV;
    init(dsNV);
    List dsQL;
    init(dsQL);
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
    system("pause");
}
