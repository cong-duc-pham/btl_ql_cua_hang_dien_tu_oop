#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <ctime>

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
    int pick = 0;
    do
    {
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
    do
    {
        cout << "Nhap so luong hang nhap ve: ";
        cin >> soLuong;
        if (soLuong <= 0)
        {
            cout << "So luong phai la so duong. Vui long nhap lai." << endl;
        }
    } while (soLuong <= 0);
    do
    {
        cout << "Nhap gia thanh: ";
        cin >> giaSP;
        if (giaSP <= 0)
        {
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
    do
    {
        cout << "Nhap mat khau (4 ky tu tro len): ";
        cin >> pass;
        if (pass.length() < 4)
        {
            cout << "Mat khau phai co it nhat 4 ky tu. Vui long nhap lai.\n";
        }
    } while (pass.length() < 4);
    int namHienTai = 2024;
    do
    {
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        int tuoi = namHienTai - namSinh;
        if (tuoi < 18 || tuoi > 70)
        {
            cout << "Nam sinh khong hop le. Vui long nhap lai.\n";
        }
    } while (namHienTai - namSinh < 18 || namHienTai - namSinh > 70);

    bool soDienThoaiHopLe = false;
    do
    {
        cout << "Nhap so dien thoai: ";
        cin >> soDienThoai;

        // Kiểm tra độ dài và ký tự đầu tiên của số điện thoại
        if (soDienThoai.length() == 10 && soDienThoai[0] == '0')
        {
            soDienThoaiHopLe = true;

            // Kiểm tra các ký tự còn lại có phải là số không
            for (int i = 1; i < 10; i++)
            {
                if (soDienThoai[i] < '0' || soDienThoai[i] > '9')
                {
                    soDienThoaiHopLe = false;
                    break;
                }
            }
        }

        if (!soDienThoaiHopLe)
        {
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

void HangHoa::setSoLuong(int soLuongMoi)
{
    soLuong = soLuongMoi;
}

int HangHoa::getSoLuongBanRa()
{
    return soLuongBanRa;
}

float HangHoa::getSoTienBanRa()
{
    return soTienBanRa;
}

void HangHoa::setSoLuongBanRa(int slBanRa)
{
    soLuongBanRa = slBanRa;
}

void HangHoa::setSoTienBanRa(float tienBanRa)
{
    soTienBanRa = tienBanRa;
}

void HangHoa::capNhatBanHang(int slBanRa, float tienBanRa)
{
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

// Cấu trúc danh sách liên kết đơn cho nhân viên
struct node
{
    NhanVien *info;
    node *next;
    node(NhanVien *nv) : info(nv), next(NULL) {}
};

class List
{
private:
    node *phead, *ptail;

public:
    List() : phead(NULL), ptail(NULL) {}

    void addTail(NhanVien *nv)
    {
        node *p = new node(nv);
        if (!phead)
        {
            phead = ptail = p;
        }
        else
        {
            ptail->next = p;
            ptail = p;
        }
    }

    bool chinhSuaNhanVien(const string &maNV)
    {
        NhanVien *nv = timKiemNhanVien(maNV);
        if (nv == NULL)
        {
            cout << "Khong tim thay nhan vien de chinh sua." << endl;
            return false;
        }
        cout << "Nhap thong tin moi cho nhan vien:" << endl;
        nv->nhapThongTin();
        return true;
    }

    NhanVien *timKiemNhanVien(const string &maNV)
    {
        node *p = phead;
        while (p != NULL)
        {
            if (p->info->getMaNV() == maNV)
            {
                return p->info;
            }
            p = p->next;
        }
        cout << "Khong tim thay nhan vien co ma " << maNV << endl;
        return NULL;
    }

    void themNhanVien(int chuc)
    {
        NhanVien *nv = createNhanVien(chuc);
        addTail(nv);
        cout << "Da them nhan vien moi thanh cong!" << endl;
    }

    bool xoaNhanVien(const string &maNV)
    {
        node *prev = NULL;
        node *curr = phead;
        while (curr != NULL)
        {
            if (curr->info->getMaNV() == maNV)
            {
                if (prev == NULL)
                {
                    phead = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                }
                if (curr == ptail)
                {
                    ptail = prev;
                }
                delete curr->info;
                delete curr;
                cout << "Da xoa nhan vien co ma " << maNV << endl;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Khong tim thay nhan vien de xoa." << endl;
        return false;
    }

    NhanVien *checkLogin(const string &sdtnv, const string &pass)
    {
        node *p = phead;
        while (p != NULL)
        {
            if (p->info->getSoDienThoai() == sdtnv && p->info->getPass() == pass)
            {
                // Kiểm tra chức vụ của nhân viên
                if (p->info->getChucVu() == "Quan ly")
                {
                    // Quản lý đăng nhập
                    cout << "Dang nhap thanh cong voi vai tro Quan Ly!" << endl;
                }
                else
                {
                    // Nhân viên bình thường
                    cout << "Dang nhap thanh cong voi vai tro Nhan Vien!" << endl;
                }
                return p->info; // Trả về thông tin nhân viên hoặc quản lý
            }
            p = p->next;
        }
        return NULL; // Trả về NULL nếu không tìm thấy
    }

    void printList()
    {
        node *p = phead;
        cout << left
             << setw(10) << "Ma NV"
             << setw(20) << "Ho Ten"
             << setw(10) << "Nam Sinh"
             << setw(15) << "So DT"
             << setw(15) << "Chuc Vu"
             << setw(15) << "Muc Luong"
             << endl;
        cout << string(85, '-') << endl;

        while (p)
        {
            if (p->info->getChucVu() != "Quan ly")
            {
                cout << *(p->info);
            }
            p = p->next;
        }
    }

    ~List()
    {
        while (phead)
        {
            node *temp = phead;
            phead = phead->next;
            delete temp->info;
            delete temp;
        }
    }
};

// Cấu trúc danh sách liên kết đơn cho sản phẩm
struct nodeSP
{
    HangHoa *info;
    nodeSP *next;
};

class ListSP
{
private:
    nodeSP *phead, *ptail;

public:
    ListSP() : phead(NULL), ptail(NULL) {}

    void addTailSP(HangHoa *sp)
    {
        nodeSP *p = new nodeSP{sp, NULL};
        if (phead == NULL)
        {
            phead = ptail = p;
        }
        else
        {
            ptail->next = p;
            ptail = p;
        }
    }

    HangHoa *timKiemSanPham(const string &idSP)
    {
        nodeSP *p = phead;
        while (p != NULL)
        {
            if (p->info->getIDHH() == idSP)
            {
                return p->info;
            }
            p = p->next;
        }
        cout << "Khong tim thay san pham co ma " << idSP << endl;
        return NULL;
    }

    bool xoaSanPham(const string &idSP)
    {
        nodeSP *prev = NULL;
        nodeSP *curr = phead;

        while (curr != NULL)
        {
            if (curr->info->getIDHH() == idSP)
            {
                if (prev == NULL)
                {
                    phead = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                }
                if (curr == ptail)
                {
                    ptail = prev;
                }
                delete curr;
                cout << "Da xoa san pham co ma " << idSP << " khoi he thong.\n";
                return true;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Khong tim thay san pham co ma " << idSP << " trong he thong.\n";
        return false;
    }

    bool chinhSuaSanPham(const string &idSP)
    {
        HangHoa *sp = timKiemSanPham(idSP);
        if (sp == NULL)
        {
            return false;
        }
        cout << "Nhap thong tin moi cho san pham:" << endl;
        sp->nhapThongTinSP();
        return true;
    }

    void muaSanPham(ListSP &dsSPBuyed, bool laKhachHangThanThiet, int &diemTichLuy, float &tongDoanhThu, const string &tenNguoiMua)
    {
        nodeSP *p = phead;
        HangHoa *sanPham = NULL;
        string tenSanPham;
        cout << "Nhap san pham muon mua: ";
        cin.ignore();
        getline(cin, tenSanPham);

        while (p != NULL)
        {
            if (p->info->getNameSP() == tenSanPham)
            {
                sanPham = p->info;
                break;
            }
            p = p->next;
        }

        if (sanPham == NULL)
        {
            cout << "Khong tim thay san pham co ten '" << tenSanPham << "'." << endl;
            return;
        }

        int soLuongMua;
        cout << "Nhap so luong muon mua: ";
        cin >> soLuongMua;

        if (sanPham->getSoLuong() < soLuongMua)
        {
            cout << "Khong du so luong de mua." << endl;
            return;
        }

        float thanhTien = soLuongMua * sanPham->getGiaSP();
        tongDoanhThu += thanhTien;

        sanPham->setSoLuong(sanPham->getSoLuong() - soLuongMua);

        if (laKhachHangThanThiet && thanhTien > 1000000)
        {
            diemTichLuy += (thanhTien / 1000000) * 100;
        }

        HangHoa *sanPhamMua = new HangHoa(*sanPham);
        sanPhamMua->setSoLuong(soLuongMua);
        addTailSP(sanPhamMua);

        // Thời gian hiện tại
        time_t now = time(0);
        tm *ltm = localtime(&now);
        string ngayThangNam = to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);

        cout << "Da mua thanh cong " << soLuongMua << " san pham: " << sanPham->getNameSP() << endl;
        cout << "So tien phai tra: " << fixed << setprecision(0) << thanhTien << " VND" << endl;
        cout << "Diem tich luy hien tai: " << diemTichLuy << endl;

        // In hóa đơn nếu cần
        char layBill;
        cout << "Khach hang co muon lay hoa don khong? (y/n): ";
        cin >> layBill;
        if (layBill == 'y' || layBill == 'Y')
        {
            ofstream billOut("Xuat_hoa_don.txt", ios::app);
            if (billOut.is_open())
            {
                billOut << "=========================== HOA DON MUA HANG ===========================\n";
                billOut << setw(25) << left << "Ten cua hang:" << "Cua Hang Dien Tu" << endl;
                billOut << setw(25) << left << "Dia chi:" << "123 Duong Le Loi, Quan 1, TP.HCM" << endl;
                billOut << setw(25) << left << "Website:" << "www.cuahangdientu.vn\n"
                        << endl;
                billOut << "---------------------------------------------------------------------\n";
                billOut << setw(25) << left << "San pham:" << sanPham->getNameSP() << endl;
                billOut << setw(25) << left << "So luong mua:" << soLuongMua << endl;
                billOut << setw(25) << left << "So tien phai tra:" << fixed << setprecision(0) << thanhTien << " VND" << endl;
                billOut.close();
                cout << "Bill da duoc xuat vao file 'Xuat_hoa_don.txt'." << endl;
            }
            else
            {
                cout << "Khong the mo file hoa don de ghi." << endl;
            }
        }
        else
        {
            cout << "Khach hang khong lay hoa don." << endl;
        }
    }

    void printListSPBuyed()
    {
        if (phead == NULL)
        {
            cout << "Danh sach rong!!\n";
            return;
        }

        nodeSP *p = phead;
        bool found = false;
        cout << left << setw(15) << "ID" << setw(30) << "Ten san pham" << setw(10) << "So luong"
             << setw(15) << "Gia (VND)" << setw(20) << "Loai san pham" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;

        while (p != NULL)
        {
            if (p->info != NULL)
            {
                found = true;
                cout << left << setw(15) << p->info->getIDHH()
                     << setw(30) << p->info->getNameSP()
                     << setw(10) << p->info->getSoLuong()
                     << setw(15) << fixed << setprecision(0) << p->info->getGiaSP()
                     << setw(20) << p->info->getLoaiSP() << endl;
            }
            else
            {
                cout << "Loi: Thong tin san pham rong!\n";
            }
            p = p->next;
        }
    }

    void xemSanPham() const
    {
        if (phead == NULL)
        {
            cout << "Danh sach san pham trong." << endl;
            return;
        }
        nodeSP *p = phead;
        bool found = false;
        cout << left << setw(15) << "ID" << setw(30) << "Ten san pham" << setw(10) << "So luong"
             << setw(15) << "Gia (VND)" << setw(20) << "Loai san pham" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;

        while (p != NULL)
        {
            if (p->info->getSoLuong() > 0)
            {
                found = true;
                cout << left << setw(15) << p->info->getIDHH()
                     << setw(30) << p->info->getNameSP()
                     << setw(10) << p->info->getSoLuong()
                     << setw(15) << fixed << setprecision(0) << p->info->getGiaSP()
                     << setw(20) << p->info->getLoaiSP() << endl;
            }
            p = p->next;
        }
        if (!found)
        {
            cout << "Danh sach san pham trong." << endl;
        }
    }
};

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
    string getsoDienThoaiKH();
};

class KhachHangThanThiet : public KhachHang
{
private:
    int diemTichLuy;

public:
    KhachHangThanThiet() : diemTichLuy(0) {}

    virtual void nhapThongTinKH()
    {
        KhachHang::nhapThongTinKH();
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
    do
    {
        cout << "Nhap mat khau (4 ky tu tro len): ";
        cin >> passKH;
        if (passKH.length() < 4)
        {
            cout << "Mat khau phai co it nhat 4 ky tu. Vui long nhap lai.\n";
        }
    } while (passKH.length() < 4);
    int namHienTai = 2024;

    do
    {
        cout << "Nhap nam sinh: ";
        cin >> namSinhKH;
        int tuoi = namHienTai - namSinhKH;
        if (tuoi < 16 || tuoi > 70)
        {
            cout << "Nam sinh khong hop le. Tuoi khong duoc nho hon 16 va khong duoc qua 70. Vui long nhap lai.\n";
        }
    } while (namHienTai - namSinhKH < 16 || namHienTai - namSinhKH > 70);

    bool soDienThoaiHopLe = false;
    do
    {
        cout << "Nhap so dien thoai: ";
        cin >> soDienThoaiKH;

        // Kiểm tra độ dài và ký tự đầu tiên của số điện thoại
        if (soDienThoaiKH.length() == 10 && soDienThoaiKH[0] == '0')
        {
            soDienThoaiHopLe = true;

            // Kiểm tra các ký tự còn lại có phải là số không
            for (int i = 1; i < 10; i++)
            {
                if (soDienThoaiKH[i] < '0' || soDienThoaiKH[i] > '9')
                {
                    soDienThoaiHopLe = false;
                    break;
                }
            }
        }

        if (!soDienThoaiHopLe)
        {
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
    // return hoTenKH;
    return hoTenKH;
}

string KhachHang::getsoDienThoaiKH()
{
    return soDienThoaiKH;
}
struct nodeKH
{
    KhachHang *info;
    nodeKH *next;

    nodeKH(KhachHang *kh) : info(kh), next(NULL) {}
};

class ListKH
{
private:
    nodeKH *phead, *ptail;

public:
    ListKH() : phead(NULL), ptail(NULL) {}

    KhachHang *timKiemKhachHang(const string &maKH)
    {
        nodeKH *p = phead;
        while (p != NULL)
        {
            if (p->info->getMaKH() == maKH)
            {
                return p->info;
            }
            p = p->next;
        }
        cout << "Khong tim thay khach hang co ma " << maKH << " trong he thong.\n";
        return NULL;
    }

    void addTailKH(KhachHang *kh)
    {
        nodeKH *p = new nodeKH(kh);
        if (phead == NULL)
        {
            phead = ptail = p;
        }
        else
        {
            ptail->next = p;
            ptail = p;
        }
    }

    KhachHang *checkLoginKH(const string &sdt, const string &pass)
    {
        nodeKH *p = phead;
        while (p != NULL)
        {
            if (p->info->getsoDienThoaiKH() == sdt && p->info->getPassKH() == pass)
            {
                return p->info;
            }
            p = p->next;
        }
        return NULL;
    }

    void printTemplateKH() const
    {
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

        nodeKH *temp = phead;
        while (temp != NULL)
        {
            KhachHang *kh = temp->info;
            KhachHangThanThiet *khtt = dynamic_cast<KhachHangThanThiet *>(kh);

            if (khtt != NULL)
            {
                // Là khách hàng thân thiết
                cout << *khtt;
            }
            else
            {
                // Là khách hàng thường
                cout << *kh;
            }

            temp = temp->next;
        }
    }
    void themKhachHang()
    {
        int loaiKH;
        cout << "Loai khach hang:\n1. Khach hang thuong\n2. Khach hang than thiet\n";
        cout << "Lua chon cua ban la: ";
        cin >> loaiKH;

        if (loaiKH == 1)
        {
            KhachHang *kh = new KhachHang();
            kh->nhapThongTinKH();
            addTailKH(kh);
        }
        else if (loaiKH == 2)
        {
            KhachHangThanThiet *kh = new KhachHangThanThiet();
            kh->nhapThongTinKH();
            addTailKH(kh);
        }
        else
        {
            cout << "Lua chon khong hop le!\n";
            return;
        }

        cout << "Da them khach hang moi thanh cong!" << endl;
    }
    bool xoaKhachHang(const string &maKH)
    {
        nodeKH *prev = NULL;
        nodeKH *curr = phead;

        while (curr != NULL)
        {
            if (curr->info->getMaKH() == maKH)
            {
                if (prev == NULL)
                {
                    phead = curr->next; // Xóa phần tử đầu tiên
                }
                else
                {
                    prev->next = curr->next; // Xóa phần tử giữa hoặc cuối
                }
                delete curr; // Giải phóng bộ nhớ
                cout << "Da xoa khach hang co ma " << maKH << endl;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Khong tim thay khach hang de xoa." << endl;
        return false;
    }
};

void TongDoanhThu(float tongDoanhThu)
{
    cout << "Tong doanh thu cua thu ngan la: " << fixed << setprecision(0) << tongDoanhThu << " VND" << endl;
}

// Hàm chính
int main()
{
    List dsNV;

    ListSP dsSP;

    ListKH dsKH;

    ListSP dsSPBuyed;

    HangHoa sp;
    string tenNguoiMua;
    int diemTichLuy = 0;
    float tongDoanhThu = 0.0;
    bool khachHangThanThiet = true;

    int screenWidth = 80;

    int login;
    int chon;
    bool returnMain;
    bool loggedOut = false;
    int luaChon;
    do
    {
        returnMain = false;
        int padding = (screenWidth - 24) / 2; // 24 là độ dài tiêu đề
        cout << string(padding, ' ');
        cout << "\033[1;31m**Sieu thi dien may DTL**\033[0m\n";
        cout << "\t\t\t\t||-1. Dang ky  ||\n";
        cout << "\t\t\t\t||-2. Dang nhap||\n";
        cout << "=>>Nhap lua chon cua ban: ";
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
                    cout << "|| 1. Nhan vien         ||" << endl;
                    cout << "|| 2. Khach hang        ||" << endl;
                    cout << "==========================" << endl;
                    cout << "==>>Moi nhap: ";
                    cin >> chon;
                }

                if (chon == 1)
                {
                    int chuc;
                    cout << "=========_+_*Dang ki*_+_=========\n";
                    cout << "________Chuc vu cua ban la________\n";
                    cout << "|| 1. Le tan.                   ++\n";
                    cout << "++ 2. Thu ngan.                 ||\n";
                    cout << "|| 3. Ban hang.                 ++\n";
                    cout << "++ 4. Ky thuat.                 ||\n";
                    cout << "|| 5. Bao tri.                  ++\n";
                    cout << "++ 6. Quan ly.                  ||\n";
                    cout << "==============*.*.*==============" << endl;
                    cout << "==>>Nhap lua chon cua ban: ";
                    cin >> chuc;

                    while (chuc < 1 || chuc > 6)
                    {
                        cout << "=---------Thong bao---------=\n";
                        cout << "* Hay chon 1 trong cac muc nay!\n";
                        cout << "=>> Nhap lua chon cua ban: ";
                        cin >> chuc;
                    }
                    if (chuc != 6)
                    {
                        dsNV.themNhanVien(chuc);
                    }
                    else
                    {
                        dsNV.themNhanVien(chuc);
                    }

                    cout << "*~*~*~Da dang ki thanh cong!!*~*~*~\n";
                    returnMain = true;
                }
                else if (chon == 2)
                {
                    int loaiKH;
                    cout << "============Dang ki=============\n";
                    cout << "||~~~~~~Loai khach hang:~~~~~~~||\n";
                    cout << "|| 1. Khach hang thuong.       ||\n";
                    cout << "|| 2. Khach hang than thiet.   ||\n";
                    cout << "||=============================||\n";
                    cout << " ~~~>> Nhap lua chon cua ban: ";
                    cin >> loaiKH;
                    if (loaiKH == 1)
                    {
                        KhachHang *kh = new KhachHang();
                        kh->nhapThongTinKH();
                        dsKH.addTailKH(kh);
                        cout << "*~*~*~Da dang ki thanh cong*~*~*~\n";
                        returnMain = true;
                    }
                    else if (loaiKH == 2)
                    {
                        KhachHangThanThiet *kh = new KhachHangThanThiet();
                        kh->nhapThongTinKH();
                        dsKH.addTailKH(kh);
                        cout << "*~*~*~Da dang ki thanh cong*~*~*~\n";
                        returnMain = true;
                    }
                    while (loaiKH < 1 || loaiKH > 2)
                    {
                        {
                            cout << "=---------Thong bao---------=\n";
                            cout << "* Hay chon 1 trong cac muc nay!\n";
                            cout << "=>> Nhap lua chon cua ban: ";
                            cin >> loaiKH;
                            if (loaiKH == 1)
                            {
                                KhachHang *kh = new KhachHang();
                                kh->nhapThongTinKH();
                                dsKH.addTailKH(kh);
                                cout << "*~*~*~Da dang ki thanh cong*~*~*~\n";
                                returnMain = true;
                            }
                            else if (loaiKH == 2)
                            {
                                KhachHangThanThiet *kh = new KhachHangThanThiet();
                                kh->nhapThongTinKH();
                                dsKH.addTailKH(kh);
                                cout << "*~*~*~Da dang ki thanh cong*~*~*~\n";
                                returnMain = true;
                            }
                        }
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
            cout << "~~Nhap mat khau: ";
            getline(cin, pass_current);

            NhanVien *user = dsNV.checkLogin(sdt_current, pass_current);
            KhachHang *khachhang = dsKH.checkLoginKH(sdt_current, pass_current);
            if (user != NULL)
            {
                cout << "*~*~*~Dang nhap thanh cong!!*~*~*~\n";
                NhanVien *nv = dynamic_cast<NhanVien *>(user);
                if (nv != NULL)
                {
                    cout << "Xin chao " << user->getHoTen() << "!\n";
                    int choose = 0;
                    cout << "Ban da dang nhap voi chuc vu " << user->getChucVu() << "\n";
                    do
                    {
                        // Menu cho nhân viên
                        if (user->getChucVu() == "Le tan")
                        {
                            cout << "V=======~*.*~*.~*[Le tan]~*.*~*.~*======V\n";
                            cout << "|| 1. Xem so luong khach hang hien tai.||\n";
                            cout << "|| 2. Them thong tin khach hang moi.   ||\n";
                            cout << "|| 3. Tim kiem thong tin khach hang.   ||\n";
                            cout << "|| 4. Them thong tin khach hang.       ||\n";
                            cout << "|| 5. Xoa thong tin khach hang.        ||\n";
                            cout << "|| 0. Dang xuat.                       ||\n";
                            cout << "^===============*.*.*.*.*===============^\n";
                            cout << "======>>>>  Moi ban nhap lua chon: ";
                        }
                        else if (user->getChucVu() == "Thu ngan")
                        {
                            cout << "V==========*~*~*~[Thu ngan]*~*~*~===========V\n";
                            cout << "|| 1. Xem danh sach cac san pham ban ra.   ||\n";
                            cout << "|| 2. Xem tong so tien thu duoc.           ||\n";
                            cout << "|| 3. Tim kiem thong tin san pham.         ||\n";
                            cout << "|| 4. Tim kiem thong tin khach hang.       ||\n";
                            cout << "|| 0. Dang xuat.                           ||\n";
                            cout << "^=================*.*.*.*.*=================^>\n";
                            cout << "======>>>>  Moi ban nhap lua chon: ";
                        }
                        else if (user->getChucVu() == "Ban hang")
                        {
                            cout << "V==========~*.*~*.~*[Ban hang]~*.*~*.~*==========V";
                            cout << "|| 1. Xem so luong khach hang hien tai.         ||\n";
                            cout << "|| 2. Xem so luong san pham con hang.           ||\n";
                            cout << "|| 3. Xem so luong san pham ban ra.             ||\n";
                            cout << "|| 4. Them san pham moi vao cua hang.           ||\n";
                            cout << "|| 5. Xoa thong tin san pham trong cua hang.    ||\n";
                            cout << "|| 6. Tim kiem thong tin san pham.              ||\n";
                            cout << "|| 0. Dang xuat.                                ||\n";
                            cout << "^====================*.*.*.*.*===================^\n";
                            cout << "=====>>>>  Moi ban nhap lua chon: ";
                        }
                        else if (user->getChucVu() == "Ky thuat")
                        {
                            cout << "V=========*~*~*~[Ky thuat]*~*~*~=========V\n";
                            cout << "|| 1. Xem danh sach khach hang hien tai.||\n";
                            cout << "|| 2. Xem danh sach san pham con hang.  ||\n";
                            cout << "|| 3. Xem danh sach san pham ban ra.    ||\n";
                            cout << "|| 0. Dang xuat.                        ||\n";
                            cout << "^================*.*.*.*.*===============^\n";
                            cout << "======>>>>  Moi ban nhap lua chon: ";
                        }
                        else if (user->getChucVu() == "Bao tri")
                        {
                            cout << "=================MENU===================\n";
                            cout << "V=============*~*~*~[Bao tri]*~*~*~==============V\n";
                            cout << "|| 1. Xem so luong khach hang hien tai          ||\n";
                            cout << "|| 2. Xem so luong san pham ban ra.             ||\n";
                            cout << "|| 0. Dang xuat.                                ||\n";
                            cout << "^====================*.*.*.*.*===================^\n";
                            cout << "======>>>>  Moi ban nhap lua chon: ";
                        }
                        else
                        {
                            cout << "V============================~*.*~*.~*~[Quan ly]~*.*~*.~*~==================================V\n";
                            cout << "|| 1. Xem so luong khach hang hien tai.                                                    ||\n";
                            cout << "|| 2. Xem danh sach nhan vien.                                                             ||\n";
                            cout << "|| 3. Xem danh sach cac mat hang con lai.                                                  ||\n";
                            cout << "|| 4. Xem danh sach cac mat hang da ban.                                                   ||\n";
                            cout << "|| 5. Xem tong so tien thu duoc.                                                           ||\n";
                            cout << "|| 6. Tim kiem thong tin nhan vien trong cua hang.                                         ||\n";
                            cout << "|| 7. Tim kiem thong tin khach hang trong cua hang.                                        ||\n";
                            cout << "|| 8. Tim kiem thong tin san pham trong cua hang.                                          ||\n";
                            cout << "|| 9. Them thong tin nhan vien moi.                                                        ||\n";
                            cout << "|| 10. Them thong tin khach hang moi.                                                      ||\n";
                            cout << "|| 11. Them thong tin hang hoa moi.                                                        ||\n";
                            cout << "|| 12. Xoa thong tin nhan vien trong cua hang.                                             ||\n";
                            cout << "|| 13. Xoa thong tin khach hang trong cua hang.                                            ||\n";
                            cout << "|| 14. Xoa thong tin san pham trong cua hang.                                              ||\n";
                            cout << "|| 15. Chinh cua thong tin quan ly.                                                        ||\n";
                            cout << "|| 16. Chinh sua thong tin nhan vien trong cua hang.                                       ||\n";
                            cout << "|| 17. Chinh sua thong tin san pham trong cua hang.                                        ||\n";
                            cout << "|| 0. Dang xuat.                                                                           ||\n";
                            cout << "^=======================================*.*.*.*.*===========================================^\n";
                            cout << "======>>>>  Moi ban nhap lua chon: ";
                        }
                        cin >> choose;
                        switch (choose)
                        {
                        case 0:
                            cout << "            =---------Thong bao---------=             \n";
                            cout << "                     Dang xuat...                    \n";
                            cout << "*~*~*~*~*~*~Hen gap lai quy khach lan sau!*~*~*~*~*~*~\n";
                            loggedOut = true;
                            returnMain = true;
                            break;
                        case 1:
                            // Xử lý tùy theo chức vụ
                            if (user->getChucVu() == "Le tan")
                            {
                                cout << "V==================================== Danh sach khach hang ==================================V\n";
                                dsKH.printTemplateKH();
                                cout << "^============================================================================================^\n";
                            }
                            else if (user->getChucVu() == "Thu ngan")
                            {
                                cout << "V================================= Danh sach san pham ban ra ===============================V\n";
                                dsSPBuyed.printListSPBuyed();
                                cout << "^===========================================================================================^\n";
                            }
                            else if (user->getChucVu() == "Ban hang")
                            {
                                cout << "V================================ So luong khach hang hien tai =============================V\n";
                                dsKH.printTemplateKH();
                                cout << "^===========================================================================================^\n";
                            }
                            else if (user->getChucVu() == "Ky thuat")
                            {
                                cout << "V================================ So luong khach hang hien tai =============================V\n";
                                dsKH.printTemplateKH();
                                cout << "^===========================================================================================^\n";
                            }
                            else if (user->getChucVu() == "Bao tri")
                            {
                                cout << "V================================ So luong khach hang hien tai =============================V\n";
                                dsKH.printTemplateKH();
                                cout << "^===========================================================================================^\n";
                            }
                            else
                            {
                                cout << "V================================ So luong khach hang hien tai =============================V\n";
                                dsKH.printTemplateKH();
                                cout << "^===========================================================================================^\n";
                            }
                            loggedOut = false;
                            break;
                        case 2:
                            if (user->getChucVu() == "Le tan")
                            {
                                dsKH.themKhachHang();
                                cout << "Them khach hang moi thanh cong!\n";
                                break;
                            }
                            else if (user->getChucVu() == "Thu ngan")
                            {
                                cout << "V==================================== Tong so tien thu duoc =================================V\n";
                                TongDoanhThu(tongDoanhThu);
                                cout << "^============================================================================================^\n";
                            }
                            else if (user->getChucVu() == "Ban hang")
                            {
                                cout << "V================================= Danh sach san pham con hang ==============================V\n";
                                cout << "ID" << "\t" << "Loai san pham" << "\t" << "Ten san pham" << "\t" << "So luong" << "\t" << "Gia" << endl;
                                dsSP.xemSanPham();
                                cout << "^============================================================================================^\n";
                            }
                            else if (user->getChucVu() == "Ky thuat")
                            {
                                cout << "V================================= Danh sach san pham con hang ==============================V\n";
                                cout << "ID" << "\t" << "Loai san pham" << "\t" << "Ten san pham" << "\t" << "So luong" << "\t" << "Gia" << endl;
                                dsSP.xemSanPham();
                                cout << "^===========================================================================================^\n";
                            }
                            else if (user->getChucVu() == "Bao tri")
                            {
                                cout << "V================================== Danh sach san pham ban ra ==============================V\n";
                                dsSPBuyed.printListSPBuyed();
                                cout << "^===========================================================================================^\n";
                            }
                            else
                            {
                                cout << "V==================================== Danh sach nhan vien ==================================V\n";
                                dsNV.printList();
                                cout << "^===========================================================================================^\n";
                            }
                            loggedOut = false;
                            break;
                        case 3:
                            if (user->getChucVu() == "Le tan")
                            {
                                string maKH;
                                cout << "Nhap ma khach hang can tim: ";
                                cin >> maKH;
                                KhachHang *kh = dsKH.timKiemKhachHang(maKH);
                                if (kh)
                                {
                                    cout << "Thong tin khach hang can tim:\n";
                                    cout << "=========================================================================================\n";
                                    cout << *kh;
                                    cout << "=========================================================================================\n";
                                }
                                else
                                {
                                    cout << "KHong tim thay khach hang can tim kiem!\n";
                                }
                            }
                            else if (user->getChucVu() == "Ban hang")
                            {
                                cout << "V================================== Danh sach san pham ban ra ==============================V\n";
                                dsSPBuyed.printListSPBuyed();
                                cout << "^===========================================================================================^\n";
                            }
                            else if (user->getChucVu() == "Ky thuat")
                            {
                                cout << "V================================= Danh sach san pham ban ra ===============================V\n";
                                dsSPBuyed.printListSPBuyed();
                                cout << "^===========================================================================================^\n";
                            }
                            else
                            {
                                cout << "V================================= Danh sach san pham con lai ===============================V\n";
                                dsSP.xemSanPham();
                                cout << "^===========================================================================================^\n";
                            }
                            loggedOut = false;
                            break;
                        case 4:
                            if (user->getChucVu() == "Quan ly")
                            {
                                cout << "V================================== Danh sach mat hang da ban ===============================V\n";
                                dsSPBuyed.printListSPBuyed();
                                cout << "^===========================================================================================^\n";
                            }
                            else if (user->getChucVu() == "Le tan")
                            {
                                HangHoa *sp = new HangHoa; // Tao doi tuong tren heap neu can luu tru
                                sp->nhapThongTinSP();
                                dsSP.addTailSP(sp); // Them vao danh sach lien ket
                                cout << "Them san pham moi thanh cong!\n";
                            }
                            else if (user->getChucVu() == "Thu ngan")
                            {
                                string maKH;
                                cout << "Nhap ma khach hang can tim: ";
                                cin >> maKH;
                                KhachHang *kh = dsKH.timKiemKhachHang(maKH);
                                if (kh)
                                {
                                    cout << "             =------------Thong tin khach hang duoc tim thay-----------=                 \n";
                                    cout << "=========================================================================================\n";
                                    cout << *kh << endl;
                                    cout << "=========================================================================================\n";
                                }
                            }
                            else if (user->getChucVu() == "Ban hang")
                            {
                                dsKH.themKhachHang();
                                cout << "Them khach hang moi thanh cong!\n";
                            }
                            loggedOut = false;
                            break;
                        case 5:
                            if (user->getChucVu() == "Quan ly")
                            {
                                // in tổng tiền thu được
                            }
                            else if ((user->getChucVu() == "Le tan") || (user->getChucVu() == "Ban hang"))
                            {
                                string idSP;
                                cout << "Nhap ma san pham can xoa: ";
                                cin >> idSP;
                                if (dsSP.xoaSanPham(idSP))
                                {
                                    cout << "~*.~*~*.~*=>> Xoa san pham thanh cong <<=~*.~*~*.~*\n";
                                }
                                else
                                {
                                    cout << "************=>> Xoa san pham that bai hoac khong tim thay ma " << idSP << " <<=************.\n";
                                }
                            }
                            loggedOut = false;
                            break;
                        case 6:
                            if (user->getChucVu() == "Quan ly")
                            {
                                string maNV;
                                cout << "Nhap ma nhan vien ban muon tim kiem: ";
                                cin >> maNV;
                                NhanVien *nv = dsNV.timKiemNhanVien(maNV);
                                if (nv)
                                {
                                    cout << "             =------------Thong tin nhan vien duoc tim thay-----------=                 \n";
                                    cout << "=========================================================================================\n";
                                    cout << *nv << endl;
                                    cout << "=========================================================================================\n";
                                }
                                else
                                {
                                    cout << "Hien tai he thong khong tim thay nhan vien voi ma nhan vien: " << maNV << endl;
                                }
                            }
                            else if (user->getChucVu() == "Ban hang")
                            {
                                string idSP;
                                cout << "Nhap ma san pham can tim: ";
                                cin >> idSP;
                                HangHoa *sp = dsSP.timKiemSanPham(idSP);
                                if (sp)
                                {
                                    cout << "He thong da tim ra ma san pham!" << endl;
                                    cout << "               =------------Thong tin san pham duoc tim thay-----------=                  \n";
                                    cout << "=========================================================================================\n";
                                    cout << *sp << endl;
                                    cout << "=========================================================================================\n";
                                }
                                else
                                {
                                    cout << "Khong tim thay san pham voi ma " << idSP << endl;
                                }
                            }
                            loggedOut = false;
                            break;

                        case 7:
                            if (user->getChucVu() == "Quan ly")
                            {
                                string maKH;
                                cout << "Nhap ma khach hang can tim: ";
                                cin >> maKH;
                                KhachHang *kh = dsKH.timKiemKhachHang(maKH);
                                if (kh)
                                {
                                    cout << "                =------------Thong tin khach hang duoc tim thay------------=             \n";
                                    cout << "=========================================================================================\n";
                                    cout << *kh << endl;
                                    cout << "=========================================================================================\n";
                                }
                                else
                                {
                                    cout << "Hien tai he thong khong tim thay nhan vien voi ma khach hang: " << maKH << endl;
                                }
                            }
                            loggedOut = false;
                            break;

                        case 8:
                            if (user->getChucVu() == "Quan ly")
                            {
                                string idSP;
                                cout << "Nhap ma san pham can tim: ";
                                cin >> idSP;
                                HangHoa *sp = dsSP.timKiemSanPham(idSP);
                                if (sp)
                                {
                                    cout << "He thong da tim ra ma san pham!" << endl;
                                    cout << "               =------------Thong tin san pham duoc tim thay-------------=               \n";
                                    cout << "=========================================================================================\n";
                                    cout << *sp << endl;
                                    cout << "=========================================================================================\n";
                                }
                                else
                                {
                                    cout << "********=>> Khong tim thay san pham voi ma " << idSP << ". <<=***********" << endl;
                                }
                            }
                            loggedOut = false;
                            break;

                        case 9:
                            if (user->getChucVu() == "Quan ly")
                            {
                                int chuc;
                                cout << "=========_+_*Dang ki*_+_=========\n";
                                cout << "________Chuc vu cua ban la________\n";
                                cout << "|| 1. Le tan.                   ++\n";
                                cout << "++ 2. Thu ngan.                 ||\n";
                                cout << "|| 3. Ban hang.                 ++\n";
                                cout << "++ 4. Ky thuat.                 ||\n";
                                cout << "|| 5. Bao tri.                  ++\n";
                                cout << "++ 6. Quan ly.                  ||\n";
                                cout << "==============*.*.*==============" << endl;
                                cout << "==>>Nhap lua chon cua ban: ";
                                cin >> chuc;
                                dsNV.themNhanVien(chuc);
                                cout << "~*.~*~*.~*=>> Them nhan vien moi thanh cong <<=~*.~*~*.~*\n";
                            }
                            loggedOut = false;
                            break;

                        case 10:
                            if (user->getChucVu() == "Quan ly")
                            {
                                HangHoa *sp = new HangHoa; // Tao doi tuong tren heap neu can luu tru
                                sp->nhapThongTinSP();
                                dsSP.addTailSP(sp); // Them vao danh sach lien ket
                                cout << "~*.~*~*.~*=>> Them san pham moi thanh cong <<=~*.~*~*.~*\n";
                            }
                            loggedOut = false;
                            break;
                        case 11:
                            if (user->getChucVu() == "Quan ly")
                            {
                                dsKH.themKhachHang();
                                cout << "~*.~*~*.~*=>> Them khach hang moi thanh cong <<=~*.~*~*.~*\n";
                            }
                            loggedOut = false;
                            break;

                        case 12:
                            if (user->getChucVu() == "Quan ly")
                            {
                                string maNV;
                                cout << "Nhap ma nhan vien can xoa: ";
                                cin >> maNV;
                                if (dsNV.xoaNhanVien(maNV))
                                {
                                    cout << "~*.~*~*.~*=>> Xoa nhan vien thanh cong <<=~*.~*~*.~*\n";
                                }
                                else
                                {
                                    cout << "*******=>> Xoa nhan vien that bai hoac khong tim thay ma " << maNV << ". <<=********\n";
                                }
                            }
                            loggedOut = false;
                            break;

                        case 13:
                            if (user->getChucVu() == "Quan ly")
                            {
                                string maKH;
                                cout << "Nhap ma khach hang can xoa: ";
                                cin >> maKH;
                                if (dsKH.xoaKhachHang(maKH))
                                {
                                    cout << "                 ~*.~*~*.~*Xoa khach hang thanh cong~*.~*~*.~*\n";
                                }
                                else
                                {
                                    cout << "*********Xoa khach hang that bai hoac khong tim thay ma " << maKH << ".**********\n";
                                }
                            }
                            loggedOut = false;
                            break;

                        case 14:
                            if (user->getChucVu() == "Quan ly")
                            {
                                string idSP;
                                cout << "Nhap ma san pham can xoa: ";
                                cin >> idSP;
                                if (dsSP.xoaSanPham(idSP))
                                {
                                    cout << "                  ~*.~*~*.~*==> Xoa san pham thanh cong <<==~*.~*~*.~*\n";
                                }
                                else
                                {
                                    cout << "**********=>> Xoa san pham that bai hoac khong tim thay ma " << idSP << " <<=***********.\n";
                                }
                            }
                            loggedOut = false;
                            break;

                        case 15:
                        {
                            string maNV;
                            cout << "Nhap ma nhan vien can chinh sua: ";
                            cin >> maNV;
                            if (dsNV.chinhSuaNhanVien(maNV))
                            {
                                cout << "          ~*.~*~*.~*=>> Chinh sua thong tin nhan vien thanh cong <<=~*.~*~*.~*n";
                            }
                            else
                            {
                                cout << "***********=>> Chinh sua that bai hoac khong tim thay ma " << maNV << " <<==************.\n";
                            }
                        }
                            loggedOut = false;
                            break;

                        case 16:
                            if (user->getChucVu() == "Quan ly")
                            {
                                cout << "Chinh sua thong tin ca nhan cua quan ly:\n";
                                user->nhapThongTin(); // Cap nhat thong tin quan ly
                                cout << "          ~*.~*~*.~*=>> Cap nhat thong tin thanh cong. <<=~*.~*~*.~*\n";
                            }
                            else
                            {
                                cout << "*********=>> Ban khong co quyen truy cap chuc nang nay. <<=************\n";
                            }
                            loggedOut = false;
                            break;

                        case 17:
                            if (user->getChucVu() == "Quan ly")
                            {
                                string idSP;
                                cout << "Nhap ma san pham can chinh sua: ";
                                cin >> idSP;
                                if (dsSP.chinhSuaSanPham(idSP))
                                {
                                    cout << "         ~*.~*~*.~*=>> Chinh sua thong tin san pham thanh cong <<=~*.~*~*.~*\n";
                                }
                                else
                                {
                                    cout << "*********=>> Chinh sua that bai hoac khong tim thay ma " << idSP << " <<=***********.\n";
                                }
                            }
                            loggedOut = false;
                            break;
                        }
                    } while (choose != 0 && !loggedOut);
                    returnMain = true;
                }
            }
            else if (khachhang != NULL)
            {
                tenNguoiMua = khachhang->getHoTenKH();
                cout << "*~*~*~Dang nhap thanh cong!!*~*~*~\n";
                cout << "Xin chao " << tenNguoiMua << "!\n";
                int chooseKH = 0;
                do
                {
                    // Menu cho khách hàng
                    cout << "V==================MENU==================V\n";
                    cout << "|| 1. Xem san pham.                    ||\n";
                    cout << "|| 2. Mua san pham.                    ||\n";
                    cout << "|| 3. San pham da mua.                 ||\n";
                    cout << "|| 0. Dang xuat.                       ||\n";
                    cout << "^=================*~*~*~~===============^\n";

                    cin >> chooseKH;
                    switch (chooseKH)
                    {
                    case 0:
                        cout << "            =---------Thong bao---------=             \n";
                        cout << "                     Dang xuat...                    \n";
                        cout << "*~*~*~*~*~*~Hen gap lai quy khach lan sau!*~*~*~*~*~*~\n";
                        returnMain = true;
                        break;
                    case 1:
                        dsSP.xemSanPham();
                        break;
                    case 2:
                        dsSP.muaSanPham(dsSPBuyed, true, diemTichLuy, tongDoanhThu, tenNguoiMua);
                        break;
                    case 3:
                        dsSPBuyed.printListSPBuyed();
                        break;
                    }
                } while (chooseKH != 0);
                returnMain = true;
            }
            else
            {
                cout << "        ... Dang nhap khong thanh cong! Vui long kiem tra lai!\n";
                returnMain = true;
                break;
            }
        }
        }
        cout << "\n      ==>> Ban co muon quay lai trang chu khong? (1: Co, 0: Khong): ";
        cin >> luaChon;
        if (luaChon == 1)
        {
            returnMain = true;
        }
        else if (luaChon == 0)
        {
            returnMain = false;
        }
    } while (returnMain && luaChon != 0);
    system("pause");
}