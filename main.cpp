#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <ctime>
#include <climits>

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
    void setNameSP(const string &name);
    void setGiaSP(long long gia);
 
};

// Khởi tạo biến static 
int NhanVien::IDNV = 0;

int NhanVien::IDQL = 0;

int HangHoa ::maHH = 0;

void HangHoa::setNameSP(const string &name)
{
    nameSP = name;
}

void HangHoa::setGiaSP(long long gia)
{
    giaSP = gia;
}

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
class Node
{
private:
    NhanVien *info;
    Node *next;

public:
    Node(NhanVien *nv) : info(nv), next(NULL) {}

    NhanVien *getInfo() const { return info; }
    void setInfo(NhanVien *nv) { info = nv; }

    Node *getNext() const { return next; }
    void setNext(Node *n) { next = n; }
};


class List
{
private:
    Node *phead, *ptail;

public:
    List() : phead(NULL), ptail(NULL) {}

    void addTail(NhanVien *nv)
    {
        Node *p = new Node(nv);
        if (!phead)
        {
            phead = ptail = p;
        }
        else
        {
            ptail->setNext(p);
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
        Node *p = phead;
        while (p != NULL)
        {
            if (p->getInfo()->getMaNV() == maNV)
            {
                return p->getInfo();
            }
            p = p->getNext();
        }
        cout << "Khong tim thay nhan vien co ma " << maNV << endl;
        return NULL;
    }

    void themNhanVien(int chuc)
    {
        NhanVien *nv = createNhanVien(chuc);
        addTail(nv);
    }

    bool xoaNhanVien(const string &maNV)
    {
        Node *prev = NULL;
        Node *curr = phead;
        while (curr != NULL)
        {
            if (curr->getInfo()->getMaNV() == maNV)
            {
                if (prev == NULL)
                {
                    phead = curr->getNext();
                }
                else
                {
                    prev->setNext(curr->getNext());
                }
                if (curr == ptail)
                {
                    ptail = prev;
                }
                delete curr->getInfo();
                delete curr;
                cout << "Da xoa nhan vien co ma " << maNV << endl;
                return true;
            }
            prev = curr;
            curr = curr->getNext();
        }
        cout << "Khong tim thay nhan vien de xoa." << endl;
        return false;
    }

    NhanVien *checkLogin(const string &sdtnv, const string &pass)
    {
        Node *p = phead;
        while (p != NULL)
        {
            if (p->getInfo()->getSoDienThoai() == sdtnv && p->getInfo()->getPass() == pass)
            {
                // Kiểm tra chức vụ của nhân viên
                if (p->getInfo()->getChucVu() == "Quan ly")
                {
                    // Quản lý đăng nhập
                    cout << "Dang nhap thanh cong voi vai tro Quan Ly!" << endl;
                }
                else
                {
                    // Nhân viên bình thường
                    cout << "Dang nhap thanh cong voi vai tro Nhan Vien!" << endl;
                }
                return p->getInfo(); // Trả về thông tin nhân viên hoặc quản lý
            }
            p = p->getNext();
        }
        return NULL; // Trả về NULL nếu không tìm thấy
    }

    void printList()
    {
        Node *p = phead;
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
            if (p->getInfo()->getChucVu() != "Quan ly")
            {
                cout << *(p->getInfo());
            }
            p = p->getNext();
        }
    }

    ~List()
    {
        while (phead)
        {
            Node *temp = phead;
            phead = phead->getNext();
            delete temp->getInfo();
            delete temp;
        }
    }
};

// Cấu trúc danh sách liên kết đơn cho sản phẩm
class nodeSP
{
private:
    HangHoa *info;
    nodeSP *next;

public:
    nodeSP(HangHoa *info = NULL, nodeSP *next = NULL)
        : info(info), next(next) {}

    HangHoa *getInfo() const { return info; }
    void setInfo(HangHoa *newInfo) { info = newInfo; }

    nodeSP *getNext() const { return next; }
    void setNext(nodeSP *newNext) { next = newNext; }
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
            ptail->setNext(p);
            ptail = p;
        }
    }

    HangHoa *timKiemSanPham(const string &idSP)
    {
        nodeSP *p = phead;
        while (p != NULL)
        {
            if (p->getInfo()->getIDHH() == idSP)
            {
                return p->getInfo();
            }
            p = p->getNext();
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
            if (curr->getInfo()->getIDHH() == idSP)
            {
                if (prev == NULL)
                {
                    phead = curr->getNext();
                }
                else
                {
                    prev->setNext(curr->getNext());
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
            curr = curr->getNext();
        }

        cout << "Khong tim thay san pham co ma " << idSP << " trong he thong.\n";
        return false;
    }
    bool chinhSuaSanPham(const string &idSP)
    {
        HangHoa *sp = timKiemSanPham(idSP);
        if (sp == NULL)
        {
            cout << "Khong tim thay san pham de chinh sua." << endl;
            return false;
        }

        int choice;
        do
        {
            cout << "\nChon thong tin can chinh sua:\n";
            cout << "1. Sua ten san pham\n";
            cout << "2. Sua so luong san pham\n";
            cout << "3. Sua loai san pham\n";
            cout << "4. Sua gia san pham\n";
            cout << "5. Sua toan bo thong tin san pham\n";
            cout << "0. Quay lai\n";
            cout << "  =>> Moi ban nhap lua chon: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                string newName;
                cout << "Nhap ten san pham moi: ";
                cin.ignore();
                getline(cin, newName);
                sp->setNameSP(newName);
                cout << "Da cap nhat ten san pham thanh cong.\n";
                break;
            }
            case 2:
            {
                int newQuantity;
                do
                {
                    cout << "Nhap so luong san pham moi: ";
                    cin >> newQuantity;
                    if (newQuantity < 0)
                    {
                        cout << "So luong khong duoc am. Vui long nhap lai.\n";
                    }
                } while (newQuantity < 0);
                sp->setSoLuong(newQuantity);
                cout << "Da cap nhat so luong san pham thanh cong.\n";
                break;
            }
            case 3:
            {
                int pick = 0;
                do
                {
                    cout << "Chon loai san pham moi: \n";
                    cout << "1. Dien Thoai di dong\n";
                    cout << "2. Laptop-may tinh bang\n";
                    cout << "3. Gia dung\n";
                    cout << "4. Tu lanh\n";
                    cout << "5. Noi dien\n";
                    cout << " =>> Moi ban nhap lua chon: ";
                    cin >> pick;
                } while (pick < 1 || pick > 5);

                switch (pick)
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
                cout << "Da cap nhat loai san pham thanh cong.\n";
                break;
            }
            case 4:
            {
                long long newPrice;
                do
                {
                    cout << "Nhap gia san pham moi: ";
                    cin >> newPrice;
                    if (newPrice <= 0)
                    {
                        cout << "Gia phai la so duong. Vui long nhap lai.\n";
                    }
                } while (newPrice <= 0);
                sp->setGiaSP(newPrice);
                cout << "Da cap nhat gia san pham thanh cong.\n";
                break;
            }
            case 5:
            {
                cout << "Nhap thong tin moi cho san pham:\n";
                sp->nhapThongTinSP();
                cout << "Da cap nhat thong tin san pham thanh cong.\n";
                break;
            }
            case 0:
                cout << "Quay lai menu chinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
            }
        } while (choice != 0);

        return true;
    }

    int maHD = 0;
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
            if (p->getInfo()->getNameSP() == tenSanPham)
            {
                sanPham = p->getInfo();
                break;
            }
            p = p->getNext();
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
        cout << "========== THANH TOAN ==========" << endl;
        
        cout << "Ten san pham: " << tenSanPham << endl;
        cout << "So luong mua: " << soLuongMua << endl;
        cout << "So tien phai tra: " << fixed << setprecision(0) << thanhTien << " VND" << endl;

        ++maHD;
        stringstream ss;
        ss << "HD" << setw(3) << setfill('0') << maHD;
        string maHoaDon = ss.str();

        HangHoa *sanPhamMua = new HangHoa(*sanPham);
        sanPhamMua->setSoLuong(soLuongMua);
        dsSPBuyed.addTailSP(sanPhamMua);
        // Thời gian hiện tại
        time_t now = time(0);
        tm *ltm = localtime(&now);
        string ngayThangNam = to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);

        string phuongThucThanhToan;
         int luaChonThanhToan;

        // Hỏi khách hàng về phương thức thanh toán
        cout << "Chon phuong thuc thanh toan: \n";
        cout << "1. Chuyen khoan\n";
        cout << "2. Tien mat\n";
        cout << "Lua chon cua ban: ";
        cin >> luaChonThanhToan;
        cout << "\n";
        if (luaChonThanhToan == 1)
        {
            phuongThucThanhToan = "Chuyen khoan";
            cout << "~*.~*~*.~*=>>Thong tin chuyen khoan <<=~*.~*~*.~*\n";
            cout << "So tai khoan: 123456789\n";
            cout << "Ngan hang: ABC Bank\n";
            cout << "Ten tai khoan: Cua Hang Dien Tu\n";
        }
        else if (luaChonThanhToan == 2)
        {
            phuongThucThanhToan = "Tien mat";
            cout << "Khach hang da chon thanh toan bang tien mat.\n";
        }
        else
        {
            cout << "Lua chon khong hop le. Mac dinh thanh toan bang tien mat.\n";
            phuongThucThanhToan = "Tien mat";
        }

        // Xác nhận thanh toán
        char xacNhanThanhToan;
        do{
            cout << "Da thanh toan thanh cong? (y/n): ";
            cin >> xacNhanThanhToan;

            if (xacNhanThanhToan != 'y' && xacNhanThanhToan != 'Y' &&
                xacNhanThanhToan != 'n' && xacNhanThanhToan != 'N') {
                cout << "Lua chon khong hop le. Vui long nhap lai (y/n).\n";
            }
        } while (xacNhanThanhToan != 'y' && xacNhanThanhToan != 'Y' &&
                xacNhanThanhToan != 'n' && xacNhanThanhToan != 'N');

        if (xacNhanThanhToan == 'y' || xacNhanThanhToan == 'Y')
        {
            cout << "Thanh toan da hoan tat. Cam on quy khach!\n";
            
            tongDoanhThu += thanhTien;

            sanPham->setSoLuong(sanPham->getSoLuong() - soLuongMua);

            
            if (laKhachHangThanThiet && thanhTien > 1000000)
            {
                diemTichLuy += (thanhTien / 1000000) * 100;
            }

            cout << "Da mua thanh cong " << soLuongMua << " san pham: " << sanPham->getNameSP() << endl;

            // In hóa đơn nếu cần
            char layBill;
            do {
                cout << "Khach hang co muon lay hoa don khong? (y/n): ";
                cin >> layBill;

                if (layBill != 'y' && layBill != 'Y' && layBill != 'n' && layBill != 'N') {
                    cout << "Lua chon khong hop le. Vui long nhap lai (y/n).\n";
                }
            } while (layBill != 'y' && layBill != 'Y' && layBill != 'n' && layBill != 'N');

            if (layBill == 'y' || layBill == 'Y') {
                ofstream billOut("Xuat_hoa_don.txt", ios::app);
                if (billOut.is_open()) {
                    billOut << "=========================== HOA DON MUA HANG ===========================\n";
                    billOut << setw(25) << left << "Ten cua hang:" << "Cua Hang Dien Tu" << endl;
                    billOut << setw(25) << left << "Dia chi:" << "123 Duong Le Loi, Quan 1, TP.HCM" << endl; 
                    billOut << setw(25) << left << "Website:" << "www.cuahangdientu.vn\n" << endl;
                    billOut << "---------------------------------------------------------------------\n";
                    billOut << setw(25) << left << "Ma hoa don:" << maHoaDon << endl;
                    billOut << setw(25) << left << "Ngay mua:" << ngayThangNam << endl;
                    billOut << setw(25) << left << "Ten nguoi mua:" << tenNguoiMua << endl;
                    billOut << setw(25) << left << "San pham:" << sanPham->getNameSP() << endl;
                    billOut << setw(25) << left << "So luong mua:" << soLuongMua << endl;
                    billOut << setw(25) << left << "So tien phai tra:" << fixed << setprecision(0) << thanhTien << " VND" << endl;
                    billOut << setw(25) << left << "So tien da tra:" << fixed << setprecision(0) << thanhTien << " VND" << endl;
                    billOut << setw(25) << left << "Phuong thuc thanh toan: " << phuongThucThanhToan << endl; ;
                
                    if (laKhachHangThanThiet) {
                        billOut << setw(25) << left << "Diem tich luy hien tai:" << diemTichLuy << endl;
                    }
                    billOut << "---------------------------------------------------------------------\n";
                    billOut << setw(25) << left << "Chinh sach doi tra:" << "Doi tra trong vong 7 ngay" << endl;
                    billOut << setw(25) << left << "Hotline ho tro:" << "0901 234 567" << endl;
                    billOut << "=====================================================================\n\n";
                    billOut.close();
                    cout << "Bill da duoc xuat vao file 'Xuat_hoa_don.txt'." << endl;
                    cout << "Diem tich luy hien tai: " << diemTichLuy << endl;
                } else {
                    cout << "Khong the mo file hoa don de ghi." << endl;
            }
            } else {
                cout << "Khach hang khong lay hoa don." << endl;
            }
        }
        else
        {
            cout << "Thanh toan khong thanh cong. Don hang bi huy.\n";
            return; 
        }

        ofstream fileOut("lich_su_mua_hang_hoa.txt", ios::app);
        if (fileOut.is_open()) {
            fileOut << "=========================== LICH SU MUA HANG ===========================\n";
            fileOut << setw(25) << left << "Ngay mua:" << ngayThangNam << endl;
            fileOut << setw(25) << left << "Ten nguoi mua:" << tenNguoiMua << endl;
            fileOut << setw(25) << left << "San pham:" << sanPham->getNameSP() << endl;
            fileOut << setw(25) << left << "So luong mua:" << soLuongMua << endl;
            fileOut << setw(25) << left << "Thanh tien:" << fixed << setprecision(0) << thanhTien << " VND" << endl;
            
            if (laKhachHangThanThiet) {
                fileOut << setw(25) << left << "Diem tich luy hien tai:" << diemTichLuy << endl;
            }
            fileOut << "=======================================================================\n\n";
            
            fileOut.close();
        } else {
            cout << "Khong the mo file de ghi." << endl;
        }
    }

    void printListSPBuyed()
    {
        if (phead == NULL)
        {
        cout << "                                       [Danh sach rong]\n";
            return;
        }

        nodeSP *p = phead;
        bool found = false;
        cout << left << setw(15) << "ID" << setw(30) << "Ten san pham" << setw(10) << "So luong"
             << setw(15) << "Gia (VND)" << setw(20) << "Loai san pham" << endl;
        cout << "-----------------------------------------------------------------------------------------" << endl;

        while (p != NULL)
        {
            if (p->getInfo() != NULL)
            {
                found = true;
                cout << left << setw(15) << p->getInfo()->getIDHH()
                     << setw(30) << p->getInfo()->getNameSP()
                     << setw(10) << p->getInfo()->getSoLuong()
                     << setw(15) << fixed << setprecision(0) << p->getInfo()->getGiaSP()
                     << setw(20) << p->getInfo()->getLoaiSP() << endl;
            }
            else
            {
                cout << "                [Loi: Thong tin san pham rong!\n";
            }
            p = p->getNext();
        }
    }

    void xemSanPham() const
    {
        if (phead == NULL)
        {
    cout << "                                           [Danh sach san pham rong]" << endl;
            return;  
        }
        nodeSP *p = phead;
        bool found = false;
        cout << left << setw(15) << "ID" << setw(30) << "Ten san pham" << setw(10) << "So luong"
             << setw(15) << "Gia (VND)" << setw(20) << "Loai san pham" << endl;
        cout << "-----------------------------------------------------------------------------------------" << endl;

        while (p != NULL)
        {
            if (p->getInfo()->getSoLuong() > 0)
            {
                found = true;
                cout << left << setw(15) << p->getInfo()->getIDHH()
                     << setw(30) << p->getInfo()->getNameSP()
                     << setw(10) << p->getInfo()->getSoLuong()
                     << setw(15) << fixed << setprecision(0) << p->getInfo()->getGiaSP()
                     << setw(20) << p->getInfo()->getLoaiSP() << endl;
            }
            p = p->getNext();
        }
        if (!found)
        {
    cout << "                                          [Danh sach san pham rong." << endl;
        }
    }
    void inThongTinSanPham(HangHoa *sp)
    {
        if (sp == NULL)
        {
            cout << "Khong co san pham de hien thi.\n";
            return;
        }
        cout << left << setw(15) << "ID" << setw(30) << "Ten san pham"
             << setw(10) << "So luong" << setw(15) << "Gia (VND)"
             << setw(20) << "Loai san pham" << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;
        cout << left << setw(15) << sp->getIDHH()
             << setw(30) << sp->getNameSP()
             << setw(10) << sp->getSoLuong()
             << setw(15) << fixed << setprecision(0) << sp->getGiaSP()
             << setw(20) << sp->getLoaiSP() << endl;
    }
    void timKiemVaInSanPham(const string &idSP)
    {
        HangHoa *sp = timKiemSanPham(idSP);
        if (sp)
        {
            cout << "He thong da tim ra san pham co ma '" << idSP << "':\n";
            inThongTinSanPham(sp);
        }
        else
        {
            cout << "********=>> Khong tim thay san pham voi ma " << idSP << ". <<=***********" << endl;
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

    void tangDiemTichLuy(int diem)
    {
        diemTichLuy += diem;
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
        << setw(15) << "N/A"
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
class NodeKH
{
private:
    KhachHang *info;
    NodeKH *next;

public:
    NodeKH(KhachHang *kh) : info(kh), next(NULL) {}

    KhachHang *getInfo() const { return info; }
    void setInfo(KhachHang *kh) { info = kh; }

    NodeKH *getNext() const { return next; }
    void setNext(NodeKH *n) { next = n; }
};

class ListKH
{
private:
    NodeKH *phead, *ptail;

public:
    ListKH() : phead(NULL), ptail(NULL) {}

    KhachHang *timKiemKhachHang(const string &maKH)
    {
        NodeKH *p = phead;
        while (p != NULL)
        {
            if (p->getInfo()->getMaKH() == maKH)
            {
                return p->getInfo();
            }
            p = p->getNext();
        }
        cout << "Khong tim thay khach hang co ma " << maKH << " trong he thong.\n";
        return NULL;
    }

    void addTailKH(KhachHang *kh)
    {
        NodeKH *p = new NodeKH(kh);
        if (phead == NULL)
        {
            phead = ptail = p;
        }
        else
        {
            ptail->setNext(p);
            ptail = p;
        }
    }

    KhachHang *checkLoginKH(const string &sdt, const string &pass)
    {
        NodeKH *p = phead;
        while (p != NULL)
        {
            if (p->getInfo()->getsoDienThoaiKH() == sdt && p->getInfo()->getPassKH() == pass)
            {
                return p->getInfo();
            }
            p = p->getNext();
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

        NodeKH *temp = phead;
        while (temp != NULL)
        {
            KhachHang *kh = temp->getInfo();
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

            temp = temp->getNext();
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
        NodeKH *prev = NULL;
        NodeKH *curr = phead;

        while (curr != NULL)
        {
            if (curr->getInfo()->getMaKH() == maKH)
            {
                if (prev == NULL)
                {
                    phead = curr->getNext(); // Xóa phần tử đầu tiên
                }
                else
                {
                    prev->setNext(curr->getNext()); // Xóa phần tử giữa hoặc cuối
                }
                if(curr = ptail)
                {
                    ptail = prev;
                }
                delete curr->getInfo();
                delete curr; // Giải phóng bộ nhớ
                cout << "Da xoa khach hang co ma " << maKH << endl;
                return true;
            }
            prev = curr;
            curr = curr->getNext();
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

    KhachHang kh;

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
        cout << "\033[1;31m================ SIEU THI DIEN MAY DTL =================\033[0m\n";
        cout << "\t\t\t\t\t\t[- 1. Dang ky   -]\n";
        cout << "\t\t\t\t\t\t[- 2. Dang nhap -]\n";
        while (true)
        {
            cout << "=>>Nhap lua chon cua ban: ";
            cin >> login;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Nhap sai, vui long nhap so nguyen (1 hoac 2)!\n";
            }
            else if (login < 1 || login > 2)
            {
                cout << "Lua chon khong hop le. Vui long nhap 1 hoac 2.\n";
            }
            else
            {
                break; 
            }
        }
        

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
                     while (true)
                    {
                        cout << "==>>Moi nhap: ";
                        cin >> chon;

                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                            cout << "Nhap sai, vui long nhap so nguyen (1 hoac 2)!\n";
                        }
                        else if (chon < 1 || chon > 2)
                        {
                            cout << "Lua chon khong hop le. Vui long nhap 1 hoac 2.\n";
                        }
                        else
                        {
                            break; // Nhập hợp lệ
                        }
                    }
                }

                if (chon == 1)
                {
                    int chuc;
                    cout << "=========_+_*Dang ki*_+_=========\n";
                    cout << "________Chuc vu cua ban la________\n";
                    cout << "[  1. Le tan.                    ]\n";
                    cout << "[  2. Thu ngan.                  ]\n";
                    cout << "[  3. Ban hang.                  ]\n";
                    cout << "[  4. Ky thuat.                  ]\n";
                    cout << "[  5. Bao tri.                   ]\n";
                    cout << "[  6. Quan ly.                   ]\n";
                    cout << "==============*.*.*==============" << endl;
                    while (true)
                    {
                        cout << "==>>Nhap lua chon cua ban: ";
                        cin >> chuc;

                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                            cout << "Nhap sai, vui long nhap so nguyen (1 den 6)!\n";
                        }
                        else if (chuc < 1 || chuc > 6)
                        {
                            cout << "Lua chon khong hop le. Vui long nhap tu 1 den 6.\n";
                        }
                        else
                        {
                            break; // Nhập hợp lệ
                        }
                    }

                    while (chuc < 1 || chuc > 6)
                    {
                        cout << "=---------Thong bao---------=\n";
                        cout << "* Hay chon 1 trong cac muc nay!\n";
                        cout << "=>> Nhap lua chon cua ban: ";
                        while (true)
                    {
                        cout << "==>>Nhap lua chon cua ban: ";
                        cin >> chuc;

                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                            cout << "Nhap sai, vui long nhap so nguyen (1 den 6)!\n";
                        }
                        else if (chuc < 1 || chuc > 6)
                        {
                            cout << "Lua chon khong hop le. Vui long nhap tu 1 den 6.\n";
                        }
                        else
                        {
                            break; // Nhập hợp lệ
                        }
                    }
                    }
                    if (chuc != 6)
                    {
                        dsNV.themNhanVien(chuc);
                    }
                    else
                    {
                        dsNV.themNhanVien(chuc);
                    }

                    cout << "*~*~*~ Da dang ki thanh cong *~*~*~\n";
                    returnMain = true;
                }
                else if (chon == 2)
                {
                int loaiKH;
                bool validInput = false; 
                do
                {
                    cout << "=============Dang ki=============\n";
                    cout << "||~~~~~~ Loai khach hang ~~~~~~~||\n";
                    cout << "|| 1. Khach hang thuong.        ||\n";
                    cout << "|| 2. Khach hang than thiet.    ||\n";
                    cout << "||==============================||\n";
                    cout << " ~~~>> Nhap lua chon cua ban: ";
                    cin >> loaiKH;

                    if (cin.fail()) 
                    {
                        cin.clear();                 
                        cin.ignore(INT_MAX, '\n');   
                        cout << "Nhap sai, vui long nhap so nguyen (1 hoac 2)!\n";
                    }
                    else if (loaiKH < 1 || loaiKH > 2) 
                    {
                        cout << "Lua chon khong hop le! Vui long chon 1 hoac 2.\n";
                    }
                    else
                    {
                        validInput = true; 
                    }
                } while (!validInput); 

                if (loaiKH == 1)
                {
                    KhachHang *kh = new KhachHang();
                    kh->nhapThongTinKH();
                    dsKH.addTailKH(kh);
                    cout << "*~*~*~ Da dang ki thanh cong *~*~*~\n";
                }
                else if (loaiKH == 2)
                {
                    KhachHangThanThiet *kh = new KhachHangThanThiet();
                    kh->nhapThongTinKH();
                    dsKH.addTailKH(kh);
                    cout << "*~*~*~ Da dang ki thanh cong *~*~*~\n";
                }
                returnMain = true; 
            }

            } while (!returnMain);
            break;
        }
        case 2:
        {
            string sdt_current, pass_current;
            cout << "============ Dang Nhap ===========\n";
            cout << "[     Nhap so dien thoai: ";
            cin.ignore();
            getline(cin, sdt_current);
            cout << "[     Nhap mat khau: ";
            getline(cin, pass_current);

            NhanVien *user = dsNV.checkLogin(sdt_current, pass_current);
            KhachHang *khachhang = dsKH.checkLoginKH(sdt_current, pass_current);
            if (user != NULL)
            {
                cout << "                *~*~*~Dang nhap thanh cong!!*~*~*~\n";
                NhanVien *nv = dynamic_cast<NhanVien *>(user);
                if (nv != NULL)
                {
                    cout << " -------- Xin chao " << user->getHoTen() << " --------- \n";
                    int choose = 0;
                    cout << " -------- Ban da dang nhap voi chuc vu " << user->getChucVu() << " ----------\n";
                    do
                    {
                        // Menu cho nhân viên
                        if (user->getChucVu() == "Le tan")
                        {
                            cout << "V=======~*.*~*.~*[Le tan]~*.*~*.~*======V\n";
                            cout << "|| 1. Xem so luong khach hang hien tai.||\n";
                            cout << "|| 2. Them thong tin khach hang moi.   ||\n";
                            cout << "|| 3. Tim kiem thong tin khach hang.   ||\n";
                            cout << "|| 4. Xoa thong tin khach hang.        ||\n";
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
                            cout << "V==========~*.*~*.~*[Ban hang]~*.*~*.~*==========V\n";
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
                            cout << "|| 10. Them thong tin hang hoa moi.                                                        ||\n";
                            cout << "|| 11. Them thong tin khach hang moi.                                                      ||\n";
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
                        if (cin.fail()) {
        					cin.clear(); 
					        cin.ignore(INT_MAX, '\n'); 
					        cout << "* Loi: Vui long nhap so nguyen!\n";
					        choose = -1; 
					        continue;
					    }
                        switch (choose)
                        {
                        case 0:
                            cout << "            =---------Thong bao---------=             \n";
                            cout << "                     Dang xuat...                    \n";
                            cout << "*~*~*~*~*~*~Hen gap lai ban lan sau!*~*~*~*~*~*~\n";
                            loggedOut = true;
                            returnMain = true;
                            break;
                        case 1:
                            // Xử lý tùy theo chức vụ
                            if (user->getChucVu() == "Le tan")
                            {
                                cout << "V======================================== Danh sach khach hang ======================================V\n";
                                dsKH.printTemplateKH();
                                cout << "^====================================================================================================^\n";
                            }
                            else if (user->getChucVu() == "Thu ngan")
                            {
                                cout << "V===================================== Danh sach san pham ban ra ===================================V\n";
                                dsSPBuyed.printListSPBuyed();
                                cout << "^===================================================================================================^\n";
                            }
                            else if (user->getChucVu() == "Ban hang")
                            {
                                cout << "V==================================== So luong khach hang hien tai =================================V\n";
                                dsKH.printTemplateKH();
                                cout << "^===================================================================================================^\n";
                            }
                            else if (user->getChucVu() == "Ky thuat")
                            {
                                cout << "V==================================== So luong khach hang hien tai =================================V\n";
                                dsKH.printTemplateKH();
                                cout << "^===================================================================================================^\n";
                            }
                            else if (user->getChucVu() == "Bao tri")
                            {
                                cout << "V==================================== So luong khach hang hien tai =================================V\n";
                                dsKH.printTemplateKH();
                                cout << "^===================================================================================================^\n";
                            }
                            else
                            {
                                cout << "V==================================== So luong khach hang hien tai =================================V\n";
                                dsKH.printTemplateKH();
                                cout << "^===================================================================================================^\n";
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
                                    cout << "             =------------Thong tin khach hang duoc tim thay-----------=                 \n";
                                    cout << left
                                        << setw(20) << "Ma KH"
                                        << setw(20) << "Ho Ten"
                                        << setw(15) << "Nam Sinh"
                                        << setw(20) << "So DT"
                                        << setw(15) << "Diem TL"
                                        << setw(20) << "Loai KH"
                                        << endl;
                                    cout << "=======================================================================================================\n";
                                    cout << *kh;
                                    cout << "=======================================================================================================\n";
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
                                string maKH;
                                cout << "Nhap ma khach hang can xoa: ";
                                cin >> maKH;
                                if (dsKH.xoaKhachHang(maKH))
                                {
                                    cout << "                 ~*.~*~*.~*Xoa khach hang thanh cong~*.~*~*.~*\n";
                                }
                                else
                                {
                                    cout << "********* Xoa khach hang that bai hoac khong tim thay ma " << maKH << ".**********\n";
                                }
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
                                    cout << left
                                        << setw(20) << "Ma KH"
                                        << setw(20) << "Ho Ten"
                                        << setw(15) << "Nam Sinh"
                                        << setw(20) << "So DT"
                                        << setw(15) << "Diem TL"
                                        << setw(20) << "Loai KH"
                                        << endl;
                                    cout << "=========================================================================================\n";
                                    cout << *kh << endl;
                                    cout << "=========================================================================================\n";
                                }
                            }
                            else if (user->getChucVu() == "Ban hang")
                            {
                                HangHoa *sp = new HangHoa; // Tao doi tuong tren heap neu can luu tru
                                sp->nhapThongTinSP();
                                dsSP.addTailSP(sp); // Them vao danh sach lien ket
                                cout << "~*.~*~*.~*=>> Them san pham moi thanh cong <<=~*.~*~*.~*\n";
                            }
                            loggedOut = false;
                            break;
                        case 5:
                            if (user->getChucVu() == "Quan ly")
                            {
                                cout << "V==================================== Tong so tien thu duoc =================================V\n";
                                TongDoanhThu(tongDoanhThu);
                                cout << "^============================================================================================^\n";
                            }
                            else if (user->getChucVu() == "Ban hang")
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
                                    cout << left
                                        << setw(10) << "Ma NV"
                                        << setw(20) << "Ho Ten"
                                        << setw(10) << "Nam Sinh"
                                        << setw(15) << "So DT"
                                        << setw(15) << "Chuc Vu"
                                        << setw(15) << "Muc Luong"
                                        << endl;
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
                                dsSP.timKiemVaInSanPham(idSP);
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
                                    cout << left
                                        << setw(20) << "Ma KH"
                                        << setw(20) << "Ho Ten"
                                        << setw(15) << "Nam Sinh"
                                        << setw(20) << "So DT"
                                        << setw(15) << "Diem TL"
                                        << setw(20) << "Loai KH"
                                        << endl;
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
                            if (user->getChucVu() == "Quan ly"){
                                string idSP;
                                cout << "Nhap ma san pham can tim: ";
                                cin >> idSP;
                                dsSP.timKiemVaInSanPham(idSP); // Sử dụng hàm mới (Thay đổi 6)
                            }
                            loggedOut = false;
                            break;
                        case 9:
                            if (user->getChucVu() == "Quan ly")
                            {
                                int chuc;
                                cout << "=========_+_*Dang ki*_+_=========\n";
                                cout << "______Chon chuc vu muon them______\n";
                                cout << "[  1. Le tan.                    ]\n";
                                cout << "[  2. Thu ngan.                  ]\n";
                                cout << "[  3. Ban hang.                  ]\n";
                                cout << "[  4. Ky thuat.                  ]\n";
                                cout << "[  5. Bao tri.                   ]\n";
                                cout << "[  6. Quan ly.                   ]\n";
                                cout << "==============*.*.*==============" << endl;
                                cout << "==>>Nhap lua chon cua ban: ";
                                cin >> chuc;
                                if (cin.fail()) {
                                    cin.clear(); 
                                    cin.ignore(INT_MAX, '\n'); 
                                    cout << "* Loi: Vui long nhap so nguyen!\n";
                                    chuc = -1; 
                                    continue;
					            }
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

                        case 16:
                        {
                            string maNV;
                            cout << "Nhap ma nhan vien can chinh sua: ";
                            cin >> maNV;
                            if (dsNV.chinhSuaNhanVien(maNV))
                            {
                                cout << "          ~*.~*~*.~*=>> Chinh sua thong tin nhan vien thanh cong <<=~*.~*~*.~*\n";
                            }
                            else
                            {
                                cout << "***********=>> Chinh sua that bai hoac khong tim thay ma " << maNV << " <<==************.\n";
                            }
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
                cout << "                *~*~*~Dang nhap thanh cong!!*~*~*~\n";
                cout << " ------------ Xin chao " << tenNguoiMua << "! ------------------\n";
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
                    cout << "=====>>>>  Moi ban nhap lua chon: ";
                    cin >> chooseKH;
                    if (cin.fail()) {
        				cin.clear(); 
					    cin.ignore(INT_MAX, '\n'); 
					    cout << "* Loi: Vui long nhap so nguyen tu 0 den 4!\n";
					    chooseKH = -1; 
					    continue;
					}
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
         while (true) {
		    cout << "\n      ==>> Ban co muon quay lai trang chu khong? (1: Co, 0: Khong): ";
		    cin >> luaChon;
		
		    if (cin.fail()) {
		        cin.clear(); 
		        cin.ignore(INT_MAX, '\n');
		        cout << "* Loi: Vui long nhap so nguyen!\n";
		        continue; 
		    }
		
		    if (luaChon == 1) {
		        returnMain = true; 
		        break; 
		    } else if (luaChon == 0) {
		        returnMain = false; 
		        break; 
		    } else {
		        cout << "* Lua chon khong hop le. Vui long nhap 1 (Co) hoac 0 (Khong)!\n";
		    }
		}
    } while (returnMain && luaChon != 0);
    system("pause");
}