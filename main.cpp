#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class NhanVien
{
protected:
    static int IDNV;
    static int IDQL;
    string maNV;
    string hoTen;
    int namSinh;
    string chucVu;
    string pass;
    string soDienThoai;
    long long mucLuong;

public:
    virtual void nhapThongTin();
    virtual void setChucVuVaLuong() = 0;
    virtual ~NhanVien() {}
    friend ostream &operator<<(ostream &out, NhanVien &a);
    string getMaNV();
    string getPass();
    string getChucVu();
    string getHoTen();
    string getSoDienThoai();
};
class HangHoa
{
private:
    static int maHH;
    string IDHH;
    int soLuong;
    string nameSP;
    long long giaSP;
    string loaiSP;

public:
    virtual void nhapThongTinSP();
    friend ostream &operator<<(ostream &out, HangHoa a);
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

void HangHoa::setLoaiSP(string loai)
{
    loaiSP = loai;
}

void HangHoa::nhapThongTinSP()
{
    cout << "Nhap ten hang hoa: ";
    cin.ignore();
    getline(cin, nameSP);
    int pick = 0;
    do {
        cout << "Chon loai san pham: " << endl;
        cout << "1. Dien Thoai di dong" << endl;
        cout << "2. Laptop-may tinh bang" << endl;
        cout << "3. Gia dung" << endl;
        cout << "4. Tu lanh" << endl;
        cout << "5. Noi dien" << endl;
        cout << "Moi ban nhap lua chon: ";
        cin >> pick;
    } while (pick < 1 || pick > 5);
    
    switch (pick)
    {
    case 1:
        setLoaiSP("Dien Thoai di dong");
        break;
    case 2:
        setLoaiSP("Laptop-may tinh bang");
        break;
    case 3:
        setLoaiSP("Gia dung");
        break;
    case 4:
        setLoaiSP("Tu lanh");
        break;
    case 5:
        setLoaiSP("Noi dien");
        break;
    }
    do {
        cout << "Nhap so luong hang nhap ve: ";
        cin >> soLuong;
        if (soLuong <= 0) {
            cout << "So luong phai la so duong. Vui long nhap lai." << endl;
        }
    } while (soLuong <= 0);
    do {
        cout << "Nhap gia thanh: ";
        cin >> giaSP;
        if (giaSP <= 0) {
            cout << "Gia thanh phai la so duong. Vui long nhap lai." << endl;
        }
    } while (giaSP <= 0);
    ++maHH;
    stringstream ss;
    ss << "HH" << setw(3) << setfill('0') << maHH;
    IDHH = ss.str(); // Gán ID cho sản phẩm
}

void NhanVien::nhapThongTin()
{

    cout << "Nhap ho ten nhan vien: ";
    cin.ignore();
    getline(cin, hoTen);
    do {
        cout << "Nhap mat khau (4 ky tu tro len): ";
        cin >> pass;
        if (pass.length() < 4) {
            cout << "Mat khau phai co it nhat 4 ky tu. Vui long nhap lai.\n";
        }
    } while (pass.length() < 4);
    int namHienTai = 2024;
    do {
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        int tuoi = namHienTai - namSinh;
        if (tuoi < 18 || tuoi > 70) {
            cout << "Nam sinh khong hop le. Vui long nhap lai.\n";
        }
    } while (namHienTai - namSinh < 18 || namHienTai - namSinh > 70);

    bool soDienThoaiHopLe = false;
    do {
        cout << "Nhap so dien thoai: ";
        cin >> soDienThoai;

        // Kiểm tra độ dài và ký tự đầu tiên của số điện thoại
        if (soDienThoai.length() == 10 && soDienThoai[0] == '0') {
            soDienThoaiHopLe = true;
            
            // Kiểm tra các ký tự còn lại có phải là số không
            for (int i = 1; i < 10; i++) {
                if (soDienThoai[i] < '0' || soDienThoai[i] > '9') {
                    soDienThoaiHopLe = false;
                    break;
                }
            }
        }

        if (!soDienThoaiHopLe) {
            cout << "So dien thoai khong hop le. Vui long nhap so 0 + 9 chu so.\n";
        }
    } while (!soDienThoaiHopLe);
}

ostream &operator<<(ostream &out, NhanVien &a)
{
    out << left << setw(10) << a.maNV      
        << setw(20) << a.hoTen            
        << setw(10) << a.namSinh          
        << setw(15) << a.soDienThoai     
        << setw(15) << a.chucVu            
        << setw(15) << a.mucLuong          
        << endl;
    return out;
}

string HangHoa::getNameSP()
{
    return nameSP;
}

long long HangHoa::getGiaSP()
{
    return giaSP;
}

string HangHoa::getLoaiSP()
{
    return loaiSP;
}

string HangHoa::getIDHH()
{
    return IDHH;
}

int HangHoa::getSoLuong()
{
    return soLuong;
}

string NhanVien::getMaNV()
{
    return maNV;
}

string NhanVien::getPass()
{
    return pass;
}
string NhanVien::getHoTen()
{
    return hoTen;
}
string NhanVien::getChucVu()
{
    return chucVu;
}
string NhanVien::getSoDienThoai()
{
    return soDienThoai;
}
// Các lớp kế thừa từ NhanVien

class LeTan : public NhanVien
{
public:
    void setChucVuVaLuong() override
    {
        chucVu = "Le tan";
        mucLuong = 2000000;
        ++IDNV;
        stringstream ss;
        ss << "NV" << setw(3) << setfill('0') << IDNV;
        maNV = ss.str();
    }
};

class ThuNgan : public NhanVien
{
public:
    void setChucVuVaLuong() override
    {
        chucVu = "Thu ngan";
        mucLuong = 4000000;
        ++IDNV;
        stringstream ss;
        ss << "NV" << setw(3) << setfill('0') << IDNV;
        maNV = ss.str();
    }
};

class BanHang : public NhanVien
{
public:
    void setChucVuVaLuong() override
    {
        chucVu = "Ban hang";
        mucLuong = 12000000;
        ++IDNV;
        stringstream ss;
        ss << "NV" << setw(3) << setfill('0') << IDNV;
        maNV = ss.str();
    }
};

class KyThuat : public NhanVien
{
public:
    void setChucVuVaLuong() override
    {
        chucVu = "Ky thuat";
        mucLuong = 20000000;
        ++IDNV;
        stringstream ss;
        ss << "NV" << setw(3) << setfill('0') << IDNV;
        maNV = ss.str();
    }
};

class BaoTri : public NhanVien
{
public:
    void setChucVuVaLuong() override
    {
        chucVu = "Bao tri";
        mucLuong = 20000000;
        ++IDNV;
        stringstream ss;
        ss << "NV" << setw(3) << setfill('0') << IDNV;
        maNV = ss.str();
    }
};

class QuanLy : public NhanVien
{
public:
    void setChucVuVaLuong() override
    {
        chucVu = "Quan ly";
        mucLuong = 30000000;
        ++IDQL; // Tăng ID quản lý
        stringstream ss;
        ss << "QL" << setw(3) << setfill('0') << IDQL; // Định dạng thành "QL" + 3 chữ số
        maNV = ss.str();
    }
};

// Cấu trúc danh sách liên kết đơn cho nhân viên
struct node
{
    NhanVien *info;
    node *next;
};

struct List
{
    node *phead, *ptail;
};

void init(List &L)
{
    L.phead = L.ptail = NULL;
}

node *createNode(NhanVien *nv)
{
    node *p = new node;
    p->info = nv;
    p->next = NULL;
    return p;
}

void addTail(List &l, NhanVien *nv)
{
    node *p = createNode(nv);
    if (l.phead == NULL)
    {
        l.phead = l.ptail = p;
    }
    else
    {
        l.ptail->next = p;
        l.ptail = p;
    }
}

void printList(List &l)
{
    node *p = l.phead;
    
    // In tiêu đề
    cout << left 
         << setw(10) << "Ma NV" 
         << setw(20) << "Ho Ten" 
         << setw(10) << "Nam Sinh" 
         << setw(15) << "So DT" 
         << setw(15) << "Chuc Vu" 
         << setw(15) << "Muc Luong" 
         << endl;
    cout << string(85, '-') << endl; 
   
    while (p != NULL)
    {
        if (p->info->getChucVu() != "Quan ly")
        {
            cout << *(p->info);
        }
        p = p->next;
    }
}

NhanVien *checkLogin(List l, string sdtnv, string pass)
{
    node *p = l.phead;
    while (p != NULL)
    {
        if (p->info->getSoDienThoai() == sdtnv && p->info->getPass() == pass)
        {
            return p->info;
        }
        p = p->next;
    }
    return NULL;
}

// Hàm tạo nhân viên dựa trên chức vụ
NhanVien *createNhanVien(int chuc)
{
    NhanVien *nv;
    if (chuc == 1)
        nv = new LeTan();
    else if (chuc == 2)
        nv = new ThuNgan();
    else if (chuc == 3)
        nv = new BanHang();
    else if (chuc == 4)
        nv = new KyThuat();
    else if (chuc == 5)
        nv = new BaoTri();
    else
        nv = new QuanLy();
    nv->nhapThongTin();
    nv->setChucVuVaLuong();
    return nv;
}

// Cấu trúc danh sách liên kết đơn cho sản phẩm
struct nodeSP
{
    HangHoa *info;
    nodeSP *next;
};

struct ListSP
{
    nodeSP *phead, *ptail;
};

void initSP(ListSP &L)
{
    L.phead = L.ptail = NULL;
}

nodeSP *createNodeSP(HangHoa *sp)
{
    nodeSP *p = new nodeSP;
    p->info = sp;
    p->next = NULL;
    return p;
}

void addTailSP(ListSP &l, HangHoa *sp)
{
    nodeSP *p = createNodeSP(sp);
    if (l.phead == NULL)
    {
        l.phead = l.ptail = p;
    }
    else
    {
        l.ptail->next = p;
        l.ptail = p;
    }
}

void printListSP(ListSP &l) {
    // In tiêu đề
    cout << left 
         << setw(15) << "Ma HH" 
         << setw(20) << "Loai SP" 
         << setw(25) << "Ten SP" 
         << setw(10) << "So Luong" 
         << setw(15) << "Gia SP" 
         << endl;
    cout << string(85, '-') << endl; // Dòng gạch ngang ngăn cách

    // In danh sách sản phẩm
    nodeSP *p = l.phead;
    while (p != NULL) {
        cout << *(p->info); // Gọi toán tử << của HangHoa để in
        p = p->next;
    }
}

HangHoa *createHangHoa(int loai)
{
    HangHoa *sp = new HangHoa();
    sp->nhapThongTinSP();
    return sp;
}
ostream &operator<<(ostream &out, HangHoa a)
{
    out << left;
    out << setw(15) << a.getIDHH() 
        << setw(20) << a.getLoaiSP() 
        << setw(25) << a.getNameSP() 
        << setw(10) << a.getSoLuong() 
        << setw(15) << a.getGiaSP() << endl;
    return out;
} 

// Khach hang
class KhachHang
{
protected:
    static int IDKH;
    string maKH;
    string hoTenKH;
    int namSinhKH;
    string passKH;
    string soDienThoaiKH;

public:
    virtual void nhapThongTinKH();
    friend ostream &operator<<(ostream &out, KhachHang &a);
    string getMaKH();
    string getPassKH();
    string getHoTenKH();
    long long getsoDienThoaiKH();
};

// khoi tao bien static cho khach hang
int KhachHang::IDKH = 0;

void KhachHang::nhapThongTinKH()
{
    ++IDKH;
    stringstream ss;
    ss << "KH" << setw(3) << setfill('0') << IDKH; // Định dạng thành "KH" + 3 chữ số
    maKH = ss.str();
    cout << "Nhap ho ten khach hang: ";
    cin.ignore();
    getline(cin, hoTenKH);
    do {
        cout << "Nhap mat khau (4 ky tu tro len): ";
        cin >> passKH;
        if (passKH.length() < 4) {
            cout << "Mat khau phai co it nhat 4 ky tu. Vui long nhap lai.\n";
        }
    } while (passKH.length() < 4);
    int namHienTai = 2024;
        
    do {
        cout << "Nhap nam sinh: ";
        cin >> namSinhKH;
        int tuoi = namHienTai - namSinhKH;
        if (tuoi < 16 || tuoi > 70) {
            cout << "Nam sinh khong hop le. Tuoi khong duoc nho hon 16 va khong duoc qua 70. Vui long nhap lai.\n";
        }
    } while (namHienTai - namSinhKH < 16 || namHienTai - namSinhKH > 70);

    bool soDienThoaiHopLe = false;
    do {
        cout << "Nhap so dien thoai: ";
        cin >> soDienThoaiKH;

        // Kiểm tra độ dài và ký tự đầu tiên của số điện thoại
        if (soDienThoaiKH.length() == 10 && soDienThoaiKH[0] == '0') {
            soDienThoaiHopLe = true;
            
            // Kiểm tra các ký tự còn lại có phải là số không
            for (int i = 1; i < 10; i++) {
                if (soDienThoaiKH[i] < '0' || soDienThoaiKH[i] > '9') {
                    soDienThoaiHopLe = false;
                    break;
                }
            }
        }

        if (!soDienThoaiHopLe) {
            cout << "So dien thoai khong hop le. Vui long nhap so 0 + 9 chu so.\n";
        }
    } while (!soDienThoaiHopLe);
}

ostream &operator<<(ostream &out, KhachHang &a)
{
    out << left;
    out << setw(20) << a.maKH 
        << setw(20) << a.hoTenKH 
        << setw(15) << a.namSinhKH 
        << setw(20) << a.soDienThoaiKH 
        << setw(20) << "N/A"
        << setw(20) << "Khach hang thuong" << endl;

    return out;
}

string KhachHang::getMaKH()
{
    return maKH;
}

string KhachHang::getPassKH()
{
    return passKH;
}
string KhachHang::getHoTenKH()
{
    return hoTenKH;
}

long long KhachHang::getsoDienThoaiKH()
{
    return stoll(soDienThoaiKH);
}
struct nodeKH
{
    KhachHang *info;
    nodeKH *next;
};

struct ListKH
{
    nodeKH *phead, *ptail;
};

void initKH(ListKH &L)
{
    L.phead = L.ptail = NULL;
}

nodeKH *createNodeKH(KhachHang *kh)
{
    nodeKH *p = new nodeKH;
    p->info = kh;
    p->next = NULL;
    return p;
}

void addTailKH(ListKH &l, KhachHang *kh)
{
    nodeKH *p = createNodeKH(kh);
    if (l.phead == NULL)
    {
        l.phead = l.ptail = p;
    }
    else
    {
        l.ptail->next = p;
        l.ptail = p;
    }
}

class KhachHangThanThiet : public KhachHang
{
private:
    int diemTichLuy;

public:
    KhachHangThanThiet() : diemTichLuy(0) {}

    virtual void nhapThongTinKH()
    { // Phương thức này vẫn là ảo (virtual) vì lớp cơ sở đã khai báo nó là virtual
        KhachHang::nhapThongTinKH();
        cout << "Nhap diem tich luy: ";
        cin >> diemTichLuy;
    }

    int getDiemTichLuy()
    {
        return diemTichLuy;
    }

    friend ostream &operator<<(ostream &out, KhachHangThanThiet &a)
    {
        out << left; // Căn trái cho tất cả các cột
        
        out << setw(20) << a.maKH 
            << setw(20) << a.hoTenKH 
            << setw(15) << a.namSinhKH 
            << setw(20) << a.soDienThoaiKH 
            << setw(15) << a.diemTichLuy 
            << setw(20) << a.getLoaiKH() << endl;

        return out;
    }

    string getLoaiKH()
    {
        if (diemTichLuy >= 1500)
        {
            return "Kim Cuong";
        }
        else if (diemTichLuy >= 1000)
        {
            return "Vang";
        }
        else if (diemTichLuy >= 500)
        {
            return "Bac";
        }
        else if (diemTichLuy >= 100)
        {
            return "Dong";
        }
        else
        {
            return "Thong thuong";
        }
    }
};

KhachHang *checkLoginKH(ListKH l, string sdt, string pass)
{
    long long int sdtNV = stoll(sdt);
    nodeKH *p = l.phead;
    while (p != NULL)
    {
        if (p->info->getsoDienThoaiKH() == sdtNV && p->info->getPassKH() == pass)
        {
            return p->info;
        }
        p = p->next;
    }
    return NULL;
}

void printTemplateKH(ListKH &dsKH) {
    // In tiêu đề
    cout << left 
         << setw(20) << "Ma KH" 
         << setw(20) << "Ho Ten" 
         << setw(15) << "Nam Sinh" 
         << setw(20) << "So DT" 
         << setw(15) << "Diem TL" 
         << setw(20) << "Loai KH" 
         << endl;
    cout << string(110, '-') << endl; // Dòng gạch ngang ngăn cách
    
    nodeKH *temp = dsKH.phead;
    while (temp != NULL) {
        KhachHang *kh = temp->info;
        KhachHangThanThiet *khtt = dynamic_cast<KhachHangThanThiet*>(kh);
        
        if (khtt != NULL) {
            // Là khách hàng thân thiết
            cout << *khtt;
        } else {
            // Là khách hàng thường
            cout << *kh;
        }

        temp = temp->next;
    }
}
// Hàm chính
int main()
{
    List dsNV;
    init(dsNV);

    List dsQL;
    init(dsQL);

    ListSP dsSP;
    initSP(dsSP);

    ListKH dsKH;
    initKH(dsKH);

    int screenWidth = 80;

    int login;
    int chon;
    bool returnMain;
    bool loggedOut = false;
    do{
        returnMain = false;
        int padding = (screenWidth - 24) / 2; // 24 là độ dài tiêu đề
        cout << string(padding, ' ');
        cout << "\033[1;31m**Sieu thi dien may DTL**\033[0m\n";
        cout << "-1. Dang ky\n";
        cout << "-2. Dang nhap\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> login;

        switch (login)
        {
        case 1:
        {
            chon = 0;
            do
            {
                while (chon < 1 || chon > 2)
                {
                    cout << endl;
                    cout << "--##Chon tu cach dang ky##--" << endl;
                    cout << "==========================" << endl;
                    cout << "1. Nhan vien" << endl;
                    cout << "2. Khach hang" << endl;
                    cout << "Moi nhap: ";
                    cin >> chon;
                }

                if (chon == 1)
                {
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

                    while (chuc < 1 || chuc > 6)
                    {
                        cout << "Hay chon 1 trong cac muc nay!\n";
                        cout << "Nhap lua chon cua ban: ";
                        cin >> chuc;
                    }

                    NhanVien *x = createNhanVien(chuc);
                    addTail(dsNV, x);
                    cout << "Da dang ki thanh cong!!\n";
                    returnMain = true;
                }
                else if (chon == 2)
                {
                    int loaiKH;
                    cout << "============Dang ki=============\n";
                    cout << "Loai khach hang: \n";
                    cout << "1. Khach hang thuong\n";
                    cout << "2. Khach hang than thiet\n";
                    cout << "Nhap lua chon cua ban: ";
                    cin >> loaiKH;

                    while (loaiKH < 1 || loaiKH > 2)
                    {
                        cout << "Hay chon 1 trong cac muc nay!\n";
                        cout << "Nhap lua chon cua ban: ";
                        cin >> loaiKH;
                    }

                    if (loaiKH == 1)
                    {
                        KhachHang *kh = new KhachHang();
                        kh->nhapThongTinKH();
                        addTailKH(dsKH, kh);
                        cout << "Da dang ki thanh cong!!\n";
                        returnMain = true;
                    }
                    else
                    {
                        KhachHangThanThiet *kh = new KhachHangThanThiet();
                        kh->nhapThongTinKH();
                        addTailKH(dsKH, kh);
                        cout << "Da dang ki thanh cong!!\n";
                        returnMain = true;
                    }
                }
            } while (!returnMain);
            break;
        }
        case 2:
        {
            string sdt_current, pass_current;
            cout << "============Dang Nhap===========\n";
            cout << "Nhap so dien thoai: ";
            cin.ignore();
            getline(cin, sdt_current);
            cout << "Nhap mat khau: ";
            getline(cin, pass_current);

            NhanVien *user = checkLogin(dsNV, sdt_current, pass_current);
            if (user != NULL) {
                cout << "Dang nhap thanh cong!!\n";
                cout << "Xin chao " << user->getHoTen() << "!\n";
                int choose = 0;
                cout << "Ban da dang nhap voi chuc vu " << user->getChucVu() << "\n";
                do {
                    // Menu cho nhân viên
                    cout << "=================MENU===================\n";
                    if (user->getChucVu() == "Le tan") {
                        cout << "               (Le tan)                 \n";
                        cout << "0. Dang xuat\n";
                        cout << "1. Xem so luong khach hang hien tai\n";
                        cout << "Moi ban nhap lua chon: ";
                        
                    } else if (user->getChucVu() == "Thu ngan") {
                        cout << "              (Thu ngan)                \n";
                        cout << "0. Dang xuat\n";
                        cout << "1. Xem danh sach cac san pham ban ra\n";
                        cout << "2. Xem tong so tien thu duoc\n";
                        cout << "Moi ban nhap lua chon: ";
                    } else if (user->getChucVu() == "Ban hang") {
                        cout << "              (Ban hang)                \n";
                        cout << "0. Dang xuat\n";
                        cout << "1. Xem so luong khach hang hien tai\n";
                        cout << "2. Xem so luong san pham con hang\n";
                        cout << "3. Xem so luong san pham ban ra\n";
                        cout << "Moi ban nhap lua chon: ";
                    } else if (user->getChucVu() == "Ky thuat") {
                        cout << "              (Ky thuat)                \n";
                        cout << "0. Dang xuat\n";
                        cout << "1. Xem danh sach khach hang hien tai\n";
                        cout << "2. Xem danh sach san pham con hang\n";
                        cout << "3. Xem danh sach san pham ban ra\n";
                        cout << "Moi ban nhap lua chon: ";
                    } else if (user->getChucVu() == "Bao tri") {
                        cout << "               (Bao tri)                \n";
                        cout << "0. Dang xuat\n";
                        cout << "1. Xem so luong khach hang hien tai\n";
                        cout << "2. Xem so luong san pham ban ra\n";
                        cout << "Moi ban nhap lua chon: ";
                    } else {
                        cout << "               (Quan ly)                \n";
                        cout << "0. Dang xuat\n";
                        cout << "1. Xem so luong khach hang hien tai\n";
                        cout << "2. Xem danh sach nhan vien\n";
                        cout << "3. Xem danh sach cac mat hang con lai\n";
                        cout << "4. Xem danh sach cac mat hang duoc ban\n";
                        cout << "5. Xem tong so tien thu duoc\n";
                        cout << "6. Them mat hang\n";
                        cout << "Moi ban nhap lua chon: ";
                    }
                    cin >> choose;
                    switch (choose) {
                        case 0:
                            cout << "Dang xuat...\n";
                            loggedOut = true;
                            returnMain = true;
                            break; 
                        case 1:
                            // Xử lý tùy theo chức vụ
                            if (user->getChucVu() == "Le tan") {
                                printTemplateKH(dsKH);
                            } else if (user->getChucVu() == "Thu ngan") {
                                // printfListHH->buyed
                            } else if (user->getChucVu() == "Ban hang") {
                                printTemplateKH(dsKH);
                            } else if (user->getChucVu() == "Ky thuat") {
                                printTemplateKH(dsKH);
                            } else if (user->getChucVu() == "Bao tri") {
                                printTemplateKH(dsKH);
                            } else {
                                printTemplateKH(dsKH);
                            }
                            break;
                        case 2:
                            if (user->getChucVu() == "Thu ngan") {
                                // printmoneyBuyed
                            } else if (user->getChucVu() == "Ban hang") {
                                cout << "ID" << "\t" << "Loai san pham" << "\t" << "Ten san pham" << "\t" << "So luong" << "\t" << "Gia" << endl;
                                printListSP(dsSP);
                            } else if (user->getChucVu() == "Ky thuat") {
                                cout << "ID" << "\t" << "Loai san pham" << "\t" << "Ten san pham" << "\t" << "So luong" << "\t" << "Gia" << endl;
                                printListSP(dsSP);
                            } else if (user->getChucVu() == "Bao tri") {
                                // printlistSPBuyed
                            }
                            else{

                                printList(dsNV);
                            }
                            break;
                        case 3:
                            if (user->getChucVu() == "Ban hang") {
                                // PrintListHHBuyed
                            } else if (user->getChucVu() == "Ky thuat") {
                                // printListSPBuyed
                            } 
                            else {
                                printListSP(dsSP);
                            }
                            break;
                        case 4:
                            if (user->getChucVu() == "Quan ly") {
                                // Code xử lý mục 5
                            }
                            break;
                        case 5:
                            if (user->getChucVu() == "Quan ly") {
                                
                            }
                            break;
                        case 6:
                            if (user->getChucVu() == "Quan ly") {
                                HangHoa *sp = new HangHoa;  // Tạo đối tượng trên heap nếu cần lưu trữ
                                sp->nhapThongTinSP();
                                addTailSP(dsSP, sp);  // Thêm vào danh sách liên kết
                            }
                            break;
                    }
                } while (choose != 0 && !loggedOut);
            }
            else {
                KhachHang *kh = checkLoginKH(dsKH, sdt_current, pass_current);
                if (kh != NULL) {
                    cout << "Dang nhap thanh cong!!\n";
                    cout << "Xin chao " << kh->getHoTenKH() << "!\n";
                    int chooseKH = 0;
                    do {
                        // Menu cho khách hàng
                        cout << "=================MENU===================\n";
                        cout << "1. Xem san pham\n";
                        cout << "2. Mua san pham\n";
                        cout << "3. Dang xuat\n";
                        cin >> chooseKH;
                        switch (chooseKH) {
                        case 1:
                            // printListSP
                            break;
                        case 2:
                            // Mua san pham
                            break;
                        }
                    } while (chooseKH != 3);
                } else {
                    cout << "Dang nhap khong thanh cong! Vui long kiem tra lai!\n";
                    returnMain = true;
                    break;
                }
                
            }
        }
        }
        int luaChon;
        cout << "\nBan co muon quay lai trang chu khong? (1: Co, 0: Khong): ";
        cin >> luaChon;
        if (luaChon == 0)
        {
            returnMain = true;
        }
    }while(returnMain);
    system("pause");
}
