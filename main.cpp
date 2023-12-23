/*Công ty điện lực quản Khách hàng với các  thông tin:  mã khách  hàng, khu vực (có nhiều khu vực,  mỗi khu  vực  có nhiều loại với  đơn giá khác nhau),  chỉ số cũ, chỉ số mới.Ví  dụ về  khu vực:
Bảng PL1.1 Dữ liệu đầu vào
Loại	Khu vực
	A0	B0	C0	D0	E0
Loại 2	450	440	430	410	400
Loại 1	500	460	450	420	410
Xây dựng chương trình với các lớp cần thiết  để tính  được số kw khách  hàng sử dụng, tính được đơn giá  của khách  hàng,  tính  được tổng tiền mà  khách  hàng phải trả.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Khai báo lớp khach_hang để lưu trữ thông tin của một khách hàng
class khach_hang {
    private:
    // Thuộc tính
    string ma_kh;
    string khu_vuc;
    int loai;
    int chi_so_cu;
    int chi_so_moi;
    double don_gia;
    double so_kw;
    double tong_tien;

    public:
    // Phương thức
    // Hàm khởi tạo mặc định (không tham số)
    khach_hang() {
        ma_kh = "";
        khu_vuc = "A0";
        loai = 1;
        chi_so_cu = 0;
        chi_so_moi = 0;
        don_gia = 0;
        so_kw = 0;
        tong_tien = 0;
    }

    // Hàm khởi tạo có tham số
    khach_hang(string ma, string kv, int l, int csc, int csm) {
        ma_kh = ma;
        khu_vuc = kv;
        loai = l;
        chi_so_cu = csc;
        chi_so_moi = csm;
        don_gia = tinh_don_gia();
        so_kw = tinh_so_Kw();
        tong_tien = tinh_tong_tien();
    }

    // Hàm nhập thông tin khách hàng
    void nhap() {
        cout << "Nhap ma khach hang: ";
        cin >> ma_kh;
        cout << "Nhap khu vuc (A0, B0, C0, D0, E0): ";
        cin >> khu_vuc;
        cout << "Nhap loai (1 hoac 2): ";
        cin >> loai;
        cout << "Nhap chi so cu: ";
        cin >> chi_so_cu;
        cout << "Nhap chi so moi: ";
        cin >> chi_so_moi;
        don_gia = tinh_don_gia();
        so_kw = tinh_so_Kw();
        tong_tien = tinh_tong_tien();
    }

    // Hàm xuất thông tin khách hàng ra màn hình
    void xuat() {
        cout << "Ma khach hang: " << ma_kh << endl;
        cout << "Khu vuc: " << khu_vuc << loai << endl;
        cout << "Chi so cu: " << chi_so_cu << endl;
        cout << "Chi so moi: " << chi_so_moi << endl;
        cout << "Don gia: " << don_gia << endl;
        cout << "So KW su dung: " << so_kw << endl;
        cout << "Tong tien phai tra: " << tong_tien << endl;
    }

    // Hàm tính đơn giá theo khu vực và loại
    double tinh_don_gia() {
        double dg = 0;
        char chu_dau = khu_vuc[0];        
        switch (chu_dau) {
        case 'A':
            if (loai == 1) dg = 500;
            else if (loai == 2) { dg = 450;}
            break;
        case 'B':
            if (loai == 1) dg = 460;
            else if (loai == 2) {dg = 440;}
            break;
        case 'C':
            if (loai == 1) dg = 450;
            else if (loai == 2) {dg = 430;}
            break;
        case 'D':
            if (loai == 1) dg = 420;
            else if (loai == 2) {dg = 410;}
            break;
        case 'E':
            if (loai == 1) dg = 410;
            else if (loai == 2) {dg = 400;}
            break;
        default:
            dg = 0;
        }
        
        return dg;
    }

    // Hàm tính số kw sử dụng
    double tinh_so_Kw() {
        return chi_so_moi - chi_so_cu;
    }

    // Hàm tính tổng tiền phải trả
    double tinh_tong_tien() {
         return so_kw * don_gia;
    }

    // Hàm lấy khu vực của khách hàng
string lay_khu_vuc() {
        return khu_vuc;
    }
};

// Hàm nhập danh sách n khách hàng
void nhap_ds(vector<khach_hang> &ds, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin khach hang thu " << i + 1 << endl;
        khach_hang kh; // gọi class với tên kh
        kh.nhap();
        ds.push_back(kh);
    }
}

// Hàm xuất danh sách khách hàng
void xuat_ds(vector<khach_hang> ds) {
    for (int i = 0; i < ds.size(); i++) {
        cout << "Thong tin khach hang thu " << i + 1 << endl;
        ds[i].xuat();
    }
}

// Hàm xuất danh sách khách hàng theo khu vực
void xuat_theo_kv(vector<khach_hang> ds, string kv) {
    cout << "Danh sach khach hang thuoc khu vuc " << kv << endl;
    for (int i = 0; i < ds.size(); i++) {
        if (ds[i].lay_khu_vuc() == kv) {
            ds[i].xuat();
        }
    }
}

// Hàm chính
int main() {
    vector<khach_hang> dsKH; // Danh sách khách hàng
    int n; // Số lượng khách hàng
    
    cout << "Nhap so luong khach hang: ";
    cin >> n;
    nhap_ds(dsKH, n); // Nhập danh sách khách hàng
    xuat_ds(dsKH); // Xuất danh sách khách hàng
    xuat_theo_kv(dsKH, "A0"); // Xuất danh sách khách hàng thuộc khu vực A
    xuat_theo_kv(dsKH, "B0"); // Xuất danh sách khách hàng thuộc khu vực B
    xuat_theo_kv(dsKH, "C0"); // Xuất danh sách khách hàng thuộc khu vực C
    xuat_theo_kv(dsKH, "D0"); // Xuất danh sách khách hàng thuộc khu vực D
    xuat_theo_kv(dsKH, "E0"); // Xuất danh sách khách hàng thuộc khu vực E
    
    return 0;
}