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
    string namSinh;
    string chucVu;
    string pass;
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
    int soLuongBanRa;
    float soTienBanRa;

public:
    virtual void nhapThongTinSP();
    friend ostream &operator<<(ostream &out, HangHoa a);
    string getNameSP();
    long long getGiaSP();
    string getLoaiSP();
    string getIDHH();
    int getSoLuong();
    void setLoaiSP(string loai);
    void setSoLuong(int x);
    void capNhatBanHang(int slBanRa, float tienBanRa);
    int getSoLuongBanRa(); 
    float getSoTienBanRa();
    void setSoLuongBanRa(int slBanRa);
    void setSoTienBanRa(float tienBanRa);
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
    cout << "Nhap so luong hang nhap ve: ";
    cin >> soLuong;
    cout << "Nhap gia thanh: ";
    cin >> giaSP;
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
    cout << "Nhap mat khau: ";
    cin >> pass;
    cout << "Nhap nam sinh: ";
    cin >> namSinh;
}

ostream &operator<<(ostream &out, NhanVien &a)
{
    out << a.maNV << "\t" << a.hoTen << "\t" << a.namSinh << "\t" << a.chucVu << "\t" << a.mucLuong << endl;
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

void HangHoa::setSoLuong(int soLuongMoi) { 
	soLuong = soLuongMoi;
} 
    
int HangHoa::getSoLuongBanRa() { 
	return soLuongBanRa; 
}

float HangHoa::getSoTienBanRa() {
	return soTienBanRa;
}

void HangHoa::setSoLuongBanRa(int slBanRa) {
	soLuongBanRa = slBanRa; 
}

void HangHoa::setSoTienBanRa(float tienBanRa) {
	 soTienBanRa = tienBanRa; 
}

void HangHoa::capNhatBanHang(int slBanRa, float tienBanRa) {
    soLuongBanRa += slBanRa;
    soTienBanRa += tienBanRa;
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
    while (p != NULL)
    {
        if (p->info->getChucVu() != "Quan ly")
        {
            cout << *(p->info);
        }
        p = p->next;
    }
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

void printListSP(ListSP &l)
{
    nodeSP *p = l.phead;
    while (p != NULL)
    {
        cout << *(p->info);
        p = p->next;
    }
}

NhanVien *checkLogin(List l, string ID, string pass)
{
    node *p = l.phead;
    while (p != NULL)
    {
        if (p->info->getMaNV() == ID && p->info->getPass() == pass)
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
HangHoa *createHangHoa(int loai)
{
    HangHoa *sp = new HangHoa();
    sp->nhapThongTinSP();

    switch (loai)
    {
    case 1:
        sp->setLoaiSP("Dien Thoai di dong");
        break;
    case 2:
        sp->setLoaiSP("Laptop-may tinh bang");
        break;
    case 3:
        sp->setLoaiSP("Gia dung");
        break;
    case 4:
        sp->setLoaiSP("Tu lanh");
        break;
    case 5:
        sp->setLoaiSP("Noi dien");
        break;
    }
    return sp;
}
ostream &operator<<(ostream &out, HangHoa a)
{
    out << a.getIDHH() << "\t" << a.getLoaiSP() << "\t" << a.getNameSP() << "\t" << a.getSoLuong() << "\t" << a.getGiaSP() << endl;
    return out;
}

// Khach hang
class KhachHang
{
protected:
    static int IDKH;
    string maKH;
    string hoTenKH;
    string namSinhKH;
    string passKH;
    long long soDienThoaiKH;

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
    cout << "Nhap mat khau: ";
    cin >> passKH;
    cout << "Nhap nam sinh: ";
    cin >> namSinhKH;
    cout << "Nhap so dien thoai: ";
    cin >> soDienThoaiKH;
}

ostream &operator<<(ostream &out, KhachHang &a)
{
    cout << "ID" << "\t" << "Ten" << "\t" << "nam sinh";
    out << a.maKH << "\t" << a.hoTenKH << "\t" << a.namSinhKH << endl;
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
    return soDienThoaiKH;
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

void printListKH(ListKH &l)
{
    nodeKH *p = l.phead;
    while (p != NULL)
    {
        cout << *(p->info);
        p = p->next;
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
        out << a.maKH << "\t" << a.hoTenKH << "\t" << a.namSinhKH << "\t"
            << a.soDienThoaiKH << "\t" << "Diem tich luy: " << a.diemTichLuy
            << "\t" << "Loai khach hang: " << a.getLoaiKH() << endl;
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

KhachHang *checkLoginKH(ListKH l, string ID, string pass)
{
    nodeKH *p = l.phead;
    while (p != NULL)
    {
        if (p->info->getMaKH() == ID && p->info->getPassKH() == pass)
        {
            return p->info;
        }
        p = p->next;
    }
    return NULL;
}

void printCentered(string text, int screenWidth) {
    int padding = (screenWidth - text.length()) / 2;  // Tính số khoảng trắng cần thêm vào để canh giữa
    cout << string(padding, ' ') << text << endl;  // In ra khoảng trắng trước khi in chuỗi
}

void muaSanPham(ListSP &dsSP, bool laKhachHangThanThiet, int &diemTichLuy, float &tongDoanhThu) {
    nodeSP *p = dsSP.phead;
    HangHoa *sanPham = nullptr;
	string tenSanPham;
	cout << "nhap san pham muon mua: ";
	cin.ignore();
	getline(cin,tenSanPham);
    
    while (p != nullptr) {
        if (p->info->getNameSP() == tenSanPham) {
            sanPham = p->info;
            break;
        }
        p = p->next;
    }

    if (sanPham == nullptr) {
        cout << "Khong tim thay san pham co ten '" << tenSanPham << "'." << endl;
        return;
    }

    int soLuongMua;
    cout << "Nhap so luong muon mua: ";
    cin >> soLuongMua;

    if (sanPham->getSoLuong() < soLuongMua) {
        cout << "Khong du so luong de mua." << endl;
        return;
    }

    float thanhTien = soLuongMua * sanPham->getGiaSP();
    tongDoanhThu += thanhTien;

    sanPham->setSoLuong(sanPham->getSoLuong() - soLuongMua);

    sanPham->capNhatBanHang(soLuongMua, thanhTien);

    if (laKhachHangThanThiet) {
        diemTichLuy += 100;
        if (thanhTien > 1000000) diemTichLuy += 100;
    }

    cout << "Da mua thanh cong " << soLuongMua << " san pham: " << sanPham->getNameSP() << endl;
    cout << "So tien phai tra: " << fixed << setprecision(0) << thanhTien << " VND" << endl;
    cout << "Diem tich luy hien tai: " << diemTichLuy << endl;
    cout << "Tong doanh thu cua thu ngan: " << fixed << setprecision(0) << tongDoanhThu << " VND" << endl;
    cout << "Ten san pham: " << sanPham->getNameSP() << endl;
    cout << "So luong da mua: " << soLuongMua << endl;
}

void xemSanPham(const ListSP &dsSP) {
    if (dsSP.phead == NULL) {
        cout << "Danh sach san pham trong." << endl;
        return;
    }
    nodeSP *p = dsSP.phead;
     bool found=false;
    cout << left << setw(15) << "ID" << setw(30) << "Ten san pham" << setw(10) << "So luong" 
         << setw(15) << "Gia (VND)" << setw(20) << "Loai san pham" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    
    while (p != NULL) {
        if(p->info->getSoLuong()>0){
             found = true;
             cout << left << setw(15) << p->info->getIDHH() 
             << setw(30) << p->info->getNameSP() 
             << setw(10) << p->info->getSoLuong()
             << setw(15) << fixed << setprecision(0) << p->info->getGiaSP()
             << setw(20) << p->info->getLoaiSP() << endl;
        }
        p = p->next;
        if(!found){
            cout << "Danh sach san pham trong" << endl;
        }
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

    HangHoa sp;
    int diemTichLuy = 0;
    float tongDoanhThu = 0.0;
    bool khachHangThanThiet = true;

    int screenWidth = 80;

    int login;
    int chon;
    bool returnMain;
    bool loggedOut = false;
    do{
        returnMain = false;
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
                    cout << "  Moi xac nhan danh tinh" << endl;
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
                    cout << *x;
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
                        cout << *kh;
                        returnMain = true;
                    }
                    else
                    {
                        KhachHangThanThiet *kh = new KhachHangThanThiet();
                        kh->nhapThongTinKH();
                        addTailKH(dsKH, kh);
                        cout << "Da dang ki thanh cong!!\n";
                        cout << *kh;
                        returnMain = true;
                    }
                }
            } while (!returnMain);
            break;
        }
        case 2:
        {
            string ID_current, pass_current;
            cout << "============Dang Nhap===========\n";
            cout << "Nhap ID: ";
            cin.ignore();
            getline(cin, ID_current);
            cout << "Nhap mat khau: ";
            getline(cin, pass_current);

            NhanVien *user = checkLogin(dsNV, ID_current, pass_current);
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
                        
                    } else if (user->getChucVu() == "Thu ngan") {
                        cout << "              (Thu ngan)                \n";
                        cout << "0. Dang xuat\n";
                        cout << "1. Xem danh sach cac san pham ban ra\n";
                        cout << "2. Xem tong so tien thu duoc\n";
                    } else if (user->getChucVu() == "Ban hang") {
                        cout << "              (Ban hang)                \n";
                        cout << "0. Dang xuat\n";
                        cout << "1. Xem so luong khach hang hien tai\n";
                        cout << "2. Xem so luong san pham con hang\n";
                        cout << "3. Xem so luong san pham ban ra\n";
                    } else if (user->getChucVu() == "Ky thuat") {
                        cout << "              (Ky thuat)                \n";
                        cout << "0. Dang xuat\n";
                        cout << "1. Xem danh sach khach hang hien tai\n";
                        cout << "2. Xem danh sach san pham con hang\n";
                        cout << "3. Xem danh sach san pham ban ra\n";
                    } else if (user->getChucVu() == "Bao tri") {
                        cout << "               (Bao tri)                \n";
                        cout << "0. Dang xuat\n";
                        cout << "1. Xem so luong khach hang hien tai\n";
                        cout << "2. Xem so luong san pham ban ra\n";
                    } else {
                        cout << "               (Quan ly)                \n";
                        cout << "0. Dang xuat\n";
                        cout << "1. Xem so luong khach hang hien tai\n";
                        cout << "2. Xem danh sach nhan vien\n";
                        cout << "3. Xem danh sach cac mat hang con lai\n";
                        cout << "4. Xem danh sach cac mat hang duoc ban\n";
                        cout << "5. Xem tong so tien thu duoc\n";
                        cout << "6. Them mat hang\n";
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
                                printListKH(dsKH);
                            } else if (user->getChucVu() == "Thu ngan") {
                                // printfListHH->buyed
                            } else if (user->getChucVu() == "Ban hang") {
                                printListKH(dsKH);
                            } else if (user->getChucVu() == "Ky thuat") {
                                printListKH(dsKH);
                            } else if (user->getChucVu() == "Bao tri") {
                                printListKH(dsKH);
                            } else {
                            printListKH(dsKH);
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
                KhachHang *kh = checkLoginKH(dsKH, ID_current, pass_current);
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
                            xemSanPham(dsSP);
                            break;
                        case 2:
                           muaSanPham(dsSP, true, diemTichLuy, tongDoanhThu);
                            break;
                        }
                    } while (chooseKH != 3);
                } else {
                    cout << "Dang nhap khong thanh cong! Vui long kiem tra lai!\n";
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
