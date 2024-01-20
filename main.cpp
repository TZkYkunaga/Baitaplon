/*. Công ty điện lực quản Khách hàng với các  thông tin:  mã khách  hàng, khu vực (có nhiều khu vực,  
mỗi khu  vực  có nhiều loại với  đơn giá khác nhau),  chỉ số cũ, chỉ số mới.Ví  dụ về  khu vực:
Bảng PL1.1 Dữ liệu đầu vào
Loại	Khu vực
	A0	B0	C0	D0	E0
Loại 2	450	440	430	410	400
Loại 1	500	460	450	420	410
Xây dựng chương trình với các lớp cần thiết  để tính  được số kw khách  hàng sử dụng, tính được đơn giá  của khách  hàng,  
tính  được tổng tiền mà  khách  hàng phải trả.
*/
#include <iostream>
#include <string.h>
using namespace std;
const int sizeds = 10000;
struct khach_hang
{
    string makh;
    string khuvuc;
    double chisocu; 
    double chisomoi;
    int loaikhuvuc;
    
    void laythongtin(){
        cout<<"Nhap ma khach hang: ";
        cin>>makh;
        cout<<"Nhap khu vuc(A0, B0, C0, D0, E0): ";
        cin>>khuvuc;
        while (khuvuc[1] !='0' || (khuvuc[0] != 'A' && khuvuc[0] != 'B' && khuvuc[0]!='C' && khuvuc[0]!='D' && khuvuc[0]!='E')) {
            cout << "Khu vuc khong ton tai vui long nhap lai! "<<endl;
            cout << "Nhap khu vuc (A0, B0, C0, D0, E0): ";
            cin >> khuvuc;
        }
        cout<<"Nhap loai khu vuc: ";
        cin>>loaikhuvuc;
        while (!kiemtraloai(loaikhuvuc)) {
        cout << "Loai khong hop le. Hay nhap lai loai (1 hoac 2): ";
        cin >> loaikhuvuc;
        }
        cout<<"Chi so cu: ";
        cin>>chisocu;
        cout<<"chi so moi: ";
        cin>>chisomoi;

    }
    bool kiemtraloai(int l) {
        return (l >= 1 && l <= 2);
    }
    double tinhsokw(){
        return chisomoi-chisocu;
    }
    double tinhsotiendien()
    {
        double sotiendien=0;


        switch (khuvuc[0])
        {
        case 'A':
            sotiendien =(loaikhuvuc==1) ?tinhsokw()*500 :tinhsokw()*450;
            break;
        case 'B':
            sotiendien =(loaikhuvuc==1) ? tinhsokw() * 460: tinhsokw()*440;
            break;
        case 'C':
            sotiendien =(loaikhuvuc ==1) ? tinhsokw() * 450 : tinhsokw()*430;
            break;
        case 'D':
            sotiendien=(loaikhuvuc == 1) ? tinhsokw() * 420: tinhsokw() * 410;
            break;
        case 'E':
            sotiendien=(loaikhuvuc == 1) ? tinhsokw() * 410 : tinhsokw() * 400;
            break;
        default:
            cout << "Khu vuc nay khong hop le !";
            break;
        }

        return sotiendien;
    }
    void xuatthongtin(){
        cout<<"Ma khach hang: "<< makh <<endl;
        cout<<"So kw dien da su dung: "<<tinhsokw()<<endl;
        cout<<"Khach hang thuoc khu vuc "<<khuvuc<<" loai "<<loaikhuvuc<<endl;
        cout<<"So tien dien can phai tra la: "<<tinhsotiendien()<<endl;
    }
    void suathongtinkhachhang(){
        string khachhangcantim;
        cout<<"Hay nhap ma khach hang ban muon sua: ";
        cin>>khachhangcantim;
            if (khachhangcantim==makh){
                cout<<"Nhap khu vuc(A0, B0, C0, D0, E0): ";
                cin>>khuvuc;
                while (khuvuc[1] !='0' || (khuvuc[0] != 'A' && khuvuc[0] != 'B' && khuvuc[0]!='C' && khuvuc[0]!='D' && khuvuc[0]!='E')) {
                    cout << "Khu vuc khong ton tai vui long nhap lai! "<<endl;
                    cout << "Nhap khu vuc (A0, B0, C0, D0, E0): ";
                    cin >> khuvuc;
                }
                cout<<"Nhap loai khu vuc: ";
                cin>>loaikhuvuc;
                while (!kiemtraloai(loaikhuvuc)) {
                cout << "Loai khong hop le. Hay nhap lai loai (1 hoac 2): ";
                cin >> loaikhuvuc;
                }
                cout<<"Chi so cu: ";
                cin>>chisocu;
                cout<<"chi so moi: ";
                cin>>chisomoi;
                return;
                }
        cout << "Khong tim thay khach hang co ma "<<khachhangcantim<< " de xoa."<<endl;
    }
    void timkiemkhachang() {
    string khachhangcantim;
    cout << "Nhap ma khach hang ban muon tim: ";
    cin >> khachhangcantim;
    if (makh == khachhangcantim) {
        xuatthongtin();
        return; // Kết thúc hàm sau khi xuất thông tin
    }
    cout << "Khong tim thay khach hang co ma "<< khachhangcantim<<" de xoa." << endl;
    }
};

void hoatdong(khach_hang *dskhachhang){
    char option;
    int n=0;
    cout<<"1 Nhap thong tin khac hang\n"
    <<"2 Xuat ra thong tin cac khach hang\n"
    <<"3 chinh sua thong tin khach hang\n"
    <<"4 tim kiem khach hang\n"
    <<"5 ket thuc chuong trinh\n";
    cout << "Vui long chon cac phuong an tren: ";
    cin>>option;
    while (option != '5') {
        switch (option) {
        case '1':
            if (n < sizeds)
            {
                dskhachhang[n].laythongtin();
                for (int i = 0; i < n; ++i){
                    if(dskhachhang[n].makh==dskhachhang[i].makh){
                        cout<<"Ma khach hang nay da duoc su su vui long nhap lai!"<<endl;
                        dskhachhang[n].laythongtin();
                        break;
                    }
                    
                }
                n++;
            }
            else
            {
            cout<<"Danh sach da day. Khong the them khach hang moi.\n";
            }
            break;
        case '2':
            if(n==0){
                cout<<"Van chua co du lieu khach hang! "<<endl;
                break;
            }
            for (int i = 0; i < n; ++i)
            {   cout<<"\n----------------------------------------------------\n";
                dskhachhang[i].xuatthongtin();
                cout<<"\n----------------------------------------------------\n";
            }
            break;
        case '3':
            for (int i = 0; i < n; ++i)
            {   cout<<"\n----------------------------------------------------\n";
                dskhachhang[i].suathongtinkhachhang();
                cout<<"\n----------------------------------------------------\n";
            }
            break;
        case '4':
            for (int i = 0; i < n; ++i)
            {   cout<<"\n----------------------------------------------------\n";
                dskhachhang[i].timkiemkhachang();
                cout<<"\n----------------------------------------------------\n";
            }
            break;
        case '5':
            cout<<"ket thuc chuong trinh";
            return ;
        default:
            cout << "Lua chon cua ban khong co trong cac phuong an\n";
            break;
        }
        cout<<"1 Nhap thong tin khac hang\n"
        <<"2 Xuat ra thong tin cac khach hang\n"
        <<"3 chinh sua thong tin khach hang\n"
        <<"4 tim kiem khach hang\n"
        <<"5 ket thuc chuong trinh\n";
        cout << "Vui long chon cac phuong an tren: ";
        cin >> option;
    }
}
int main(){
    cout << "  _____                    _______ _    ____                      _      _   _____  _              _                \n"
                 " / ____|                  |__   __(_)  / __ \\                    | |    (_) |  __ \\(_)            | |               \n"
                 "| |     ___  _ __   __ _     | |   _  | |  | |_   _  __ _ _ __   | |     _  | |  | |_  ___ _ __   | |    _   _  ___ \n"
                 "| |    / _ \\| '_ \\ / _` |    | |  | | | |  | | | | |/ _` | '_ \\  | |    | | | |  | | |/ _ \\ '_ \\  | |   | | | |/ __|\n"
                 "| |___| (_) | | | | (_| |    | |  | | | |__| | |_| | (_| | | | | | |____| | | |__| | |  __/ | | | | |___| |_| | (__ \n"
                 " \\_____\\___/|_| |_|\\__, |    |_|  |_|  \\___/ \\__,_|\\__,_|_| |_| |______|_| |_____/|_|\\___|_| |_| |______\\__,_|\\___|\n"
                 "                    __/ |                                                                                           \n"
                 "                   |___/                                                                                            \n";
    cout<<"khuvuc	A0	B0	C0	D0	E0\n"
    <<"Loai 2	450	440	430	410	400\n"
    <<"Loai 1	500	460	450	420	410\n";
    khach_hang *dskhachhang = new khach_hang[sizeds]; 
    hoatdong(dskhachhang);
    delete [] dskhachhang;
    return 0;
}
