#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class NhanVien{
    private:
        static int ID;
        string maNV;
        string hoTen;
        string namSinh;
        string chucVu;
        string pass;
        long long mucLuong;
    public:
        friend istream& operator >> (istream& in, NhanVien& a);
        friend ostream& operator << (ostream& out, NhanVien a);
        string getMaNV();
        string getPass();
};

int NhanVien::ID = 0;

istream& operator >> (istream& in, NhanVien& a){
    ++a.ID;
    stringstream ss;
    ss << "NV" << setw(3) << setfill('0') << a.ID; // Định dạng thành "NV" + 3 chữ số
    a.maNV = ss.str();
    int chuc;
    cout << "Nhap ho ten nhan vien: ";in.ignore();
    getline(in, a.hoTen);
    cout << "Nhap mat khau: ";
    in >> a.pass;
    cout << "Nhap nam sinh: ";
    in >> a.namSinh;
    
    cout << "Chuc vu cua ban la: \n";
    cout << "1. Le tan\n";
    cout << "2. Thu ngan\n";
    cout << "3. Ban hang\n";
    cout << "4. Ky thuat\n";
    cout << "5. Bao tri\n";
    cout << "Nhap lua chon cua ban: ";
    cin >> chuc;
    while(chuc < 1 || chuc > 5){
        cout <<"Hay chon 1 trong cac muc nay!\n";
        cout << "Chuc vu cua ban la: \n";
        cout << "1. Le tan\n";
        cout << "2. Thu ngan\n";
        cout << "3. Ban hang\n";
        cout << "4. Ky thuat\n";
        cout << "5. Bao tri\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> chuc;
    }
    if(chuc == 1){
        a.chucVu = "Le tan";
    }
    else if(chuc == 2){
        a.chucVu = "Thu ngan";
    }
    else if(chuc == 3){
        a.chucVu = "Ban hang";
    }
    else if(chuc == 4){
        a.chucVu = "Ky thuat";
    }
    else{
        a.chucVu = "Bao tri";
    }
    cout << "Nhap muc luong: ";
    in >> a.mucLuong;
    return in;
}
ostream& operator << (ostream& out, NhanVien a){
    out << a.maNV << "\t" << a.hoTen <<"\t" << a.namSinh << "\t" << a.chucVu << "\t" << a.mucLuong << endl;
}

struct node{
    NhanVien info;
    node *next;
};
struct List{
    node *phead, *ptail;
};
void init(List& L){
    L.phead = L.ptail = NULL;
}
node* createNode(NhanVien nv) {
    node* p = new node;
    p->info = nv;
    p->next = NULL;
    return p;
}
void addTail(List& l, NhanVien nv) {
    node* p = createNode(nv);
    if (l.phead == nullptr) {
        l.phead = l.ptail = p;
    } else {
        l.ptail->next = p;
        l.ptail = p;
    }
}
void printList(List l) {
    node* p = l.phead;
    while (p != nullptr) {
        cout << p->info;
        p = p->next;
    }
}

string NhanVien::getMaNV(){
    return maNV;
}

string NhanVien::getPass(){
    return pass;
}

bool checkLogin(List l, string ID, string pass){
    node* p = l.phead;
    while (p != NULL) {
        if (p->info.getMaNV() == ID && p->info.getPass() == pass) {
            return true;
        }
        p = p->next;
    }
    return false;
}

int main(){
    List dsNV;
    init(dsNV);
    int login;
    do {cout << "**Chao mung den voi cua hang dien thoai di dong va thiet bi dien tu tieu dung DTL**\n";
        cout << "-1. Dang ky\n";
        cout << "-2. Dang nhap\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> login;
        
        while (login < 1 || login > 2) {
            cout << "Hay chon 1 trong cac muc nay!\n";
            cout << "1. Dang ky\n";
            cout << "2. dang nhap\n";
            cout << "Nhap lua chon cua ban: ";
            cin >> login;
        }
        if (login == 1) {
            NhanVien x;
            cout << "============Dang ki=============\n";
            cin >> x;
            addTail(dsNV, x);
            cout << "Da Dang ki thanh cong!!\n";

        } else if (login == 2) {
            string ID_current, pass_current;
            cout << "============Dang Nhap===========\n";
            cout << "Nhap ID: ";
            cin.ignore();
            getline(cin, ID_current);
            cout << "Nhap mat khau: ";
            getline(cin, pass_current);
            if (checkLogin(dsNV, ID_current, pass_current)) {
                cout << "Dang nhap thanh cong!!\n";
            } else {
                cout << "ID hoac mat khau khong dung!\n";
            }
        }
        cout << "\nBan co muon quay lai trang chu khong? (1: Co, 0: Khong): ";
        cin >> login;
    } while (login == 1);
    system("pause");
}