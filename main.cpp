#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Khai báo class khach_hang de luu tru thông tin cua mot khách hàng
class khach_hang {
    private:
    // Thuoc tính
    string ma_kh;
    string khu_vuc;
    int loai;
    int chi_so_cu;
    int chi_so_moi;
    long double don_gia;
    long double so_kw;
    long double tong_tien;
    public:
    // Phuong thuc
    // Ham khoi tao mac dinh (khong tham so)
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
    // Ham khoi tao co tham so
    khach_hang(string ma, string kv, int l, int csc, int csm) {
        ma_kh = ma;
        khu_vuc = kv;
        if (kiem_tra_loai(l)) {
            loai = l;
        }
        else {
            cout << "Loai khong hop le. Dat gia tri mac dinh 1.\n";
            loai = 1;
        }
        chi_so_cu = csc;
        chi_so_moi = csm;
        don_gia = tinh_don_gia();
        so_kw = tinh_so_Kw();
        tong_tien = tinh_tong_tien();
    }
    //kiem tra loai
    bool kiem_tra_loai(int l) {
        return (l >= 1 && l <= 2);
    }
   
    // Ham nhap thong tin khach hang
    void nhap() {
        cout << "Nhap ma khach hang: ";
        cin >> ma_kh;
        cout << "Nhap khu vuc (A0, B0, C0, D0, E0): ";
        cin >> khu_vuc;
        while (khu_vuc[1] !='0' || (khu_vuc[0] != 'A' && khu_vuc[0] != 'B' && khu_vuc[0]!='C' && khu_vuc[0]!='D' && khu_vuc[0]!='E')) {
            cout << "Khu vuc khong ton tai vui long nhap lai! "<<endl;
            cout << "Nhap khu vuc (A0, B0, C0, D0, E0): ";
            cin >> khu_vuc;
        }
        cout << "Nhap loai (1 hoac 2): ";
        cin >> loai;
        while (!kiem_tra_loai(loai)) {
        cout << "Loai khong hop le. Hay nhap lai loai (1 hoac 2): ";
        cin >> loai;
        }


        while(true) {
            cout << "Nhap chi so cu: ";
            cin >> chi_so_cu;
            cout << "Nhap chi so moi: ";
            cin >> chi_so_moi;
            if (chi_so_cu >= 0 and chi_so_moi > chi_so_cu) break;
            else cout << "Chi so khong hop le. Vui long nhap lai." << endl;
        }
        don_gia = tinh_don_gia();
        so_kw = tinh_so_Kw();
        tong_tien = tinh_tong_tien();
    }


    // Ham xuat thong tin khach hang ra man hinh
    void xuat() {
        cout << "Ma khach hang: " << ma_kh << endl;
        cout << "Khu vuc: " << khu_vuc << loai << endl;
        cout << "Chi so cu: " << chi_so_cu << endl;
        cout << "Chi so moi: " << chi_so_moi << endl;
        cout << "Don gia: " << don_gia << endl;
        cout << "So KW su dung: " << so_kw << endl;
        cout << "Tong tien phai tra: " << tong_tien << endl;
    }
    // Ham tinh don gia theo khu vuc va loai
    long double tinh_don_gia() {
        long double dg = 0;
        char chu_dau = khu_vuc[0];
        switch (chu_dau) {
        case 'A':
            if (loai == 1) dg = 500;
            else if (loai == 2) dg = 450;
            break;
        case 'B':
            if (loai == 1) dg = 460;
            else if (loai == 2) dg = 440;
            break;
        case 'C':
            if (loai == 1) dg = 450;
            else if (loai == 2) dg = 430;
            break;
        case 'D':
            if (loai == 1) dg = 420;
            else if (loai == 2) dg = 410;
            break;
        case 'E':
            if (loai == 1) dg = 410;
            else if (loai == 2) dg = 400;
            break;

        default: dg = 0;
        }
       
        return dg;
    }
    // Ham tinh so kw
    long double tinh_so_Kw() {
        return chi_so_moi - chi_so_cu;
    }
    // Ham tinh tong tien phai tra
    long double tinh_tong_tien() {
        return so_kw * don_gia;
    }
    // Hàm lay khu vuc cua khách hàng
    string lay_khu_vuc() {
        return khu_vuc;
    }
    bool trung_lap_ma_khach_hang(string ma) {
        return ma == ma_kh;
    }

    // Phương thức lấy mã khách hàng
    string lay_ma_khach_hang() {
        return ma_kh;
    }
};


// Ham nhap thong tin khach hang
void nhap_tt(vector<khach_hang> &ds) {
    khach_hang kh;
    kh.nhap();

//kiemtra nhap ma khach hang
    while (true) {
        bool trungLap = false;
        for (int i = 0; i < ds.size(); i++) {
            if (ds[i].trung_lap_ma_khach_hang(kh.lay_ma_khach_hang())) {
                cout << "Nhan thay ma khach hang nay da duoc su dung. Vui long chon ma khac!" << endl;
                trungLap = true;
                kh.nhap();
                break;
            }
        }

        if (!trungLap) {
            ds.push_back(kh);
            break; // Kết thúc vòng lặp nếu không trùng lặp
        }
    }
}


// Ham xuat danh sach khach hang theo khu vuc
void xuat_theo_kv(vector<khach_hang> ds, string kv) {
    for (int i = 0; i < ds.size(); i++) {
        if (ds[i].lay_khu_vuc() == kv) {
            cout << "----------------------------------------------------------------------------\n";
            cout << "Danh sach khach hang thuoc khu vuc " << kv << endl;
            ds[i].xuat();
        }
    }
}


void xoa_man_hinh() {
    system("cls");
}


int main() {
    xoa_man_hinh();
    int n;
    vector<khach_hang> dsKH; // Danh sach khach hang
   
    while (true) {
        cout << "\n1. Nhap 1 de cung cap thong tin khach hang";
        cout << "\n2. Nhap 2 de ket thuc" << endl;
        cout << "Nhap: ";
        cin >> n;
        while (n != 1 and n != 2) {
            cout << "Lua chon khong hop le. Vui long nhap lai: ";
            cin >> n;
        }
       
        if (n == 1) {
            xoa_man_hinh();
            cout << "\n\n\t\t=============Thong tin=============\n";
            nhap_tt(dsKH); // Nhap danh sach khach hang
        }


        else {
            break;
        }


    xoa_man_hinh();
    cout << "\t\t\t=============Tiep tuc=============";
    }


    xuat_theo_kv(dsKH, "A0"); // Xuat danh sach khach hang thuoc khu vuc A0
    xuat_theo_kv(dsKH, "B0"); // Xuat danh sach khach hang thuoc khu vuc B0
    xuat_theo_kv(dsKH, "C0"); // Xuat danh sach khach hang thuoc khu vuc C0
    xuat_theo_kv(dsKH, "D0"); // Xuat danh sach khach hang thuoc khu vuc D0
    xuat_theo_kv(dsKH, "E0"); // Xuat danh sach khach hang thuoc khu vuc E0
    cout << "\n\n\t\t=============End=============";


    return 0;
}
