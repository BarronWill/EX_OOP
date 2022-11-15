#include<iostream>
#include<windows.h>
#include<conio.h>
#include<iomanip>
using namespace std;
class Phieu;
class Nhan_vien{
    private:
        char Tennv[20];
        char Chuc_vu[20];
    public:
        void get();
        void show();
};

class Taisan{
    private:
        char Tents[30];
        char Tinh_trang[30];
        int Soluong;
    public:
        void get();
        void show();
    friend class Phieu;
    friend void Sua_Phieu(Phieu& a);
    friend void Sap_xep(Phieu& a);
};

class Phong{
    private:
        char Ten_Phong[20];
        char Ma_Phong[10];
        char Truong_Phong[20];
    public:
        void get();
        void show();
};

class Phieu{
    private:
        char Ma_Phieu[10];
        char Ngay_Kiem[15];
        int n;
        Taisan* x;
        Phong p;
        Nhan_vien nv;
    public:
        void get();
        void show();
    friend void Sua_Phieu(Phieu& a);
    friend void Sap_xep(Phieu& a);
};

void Taisan::get(){
    cout<<"Ten tai san: "; fflush(stdin); gets(Tents);
    cout<<"So luong: "; cin>>Soluong;
    cout<<"Tinh trang: "; fflush(stdin); gets(Tinh_trang);
}
void Taisan::show(){
    cout<<setw(15)<<Tents<<setw(14)<<Soluong<<setw(26)<<Tinh_trang<<endl;
}

void Phong::get(){
    cout<<"Kiem ke tai phong: "; fflush(stdin); gets(Ten_Phong);
    cout<<"Ma phong: "; fflush(stdin); gets(Ma_Phong);
    cout<<"Truong phong: "; fflush(stdin); gets(Truong_Phong);
}
void Phong::show(){
    cout<<setw(19)<<"Kiem ke tai phong: "<<Ten_Phong<<setw(27)<<"Ma phong: "<<Ma_Phong<<endl;
    cout<<setw(14)<<"Truong phong: "<<Truong_Phong<<endl;
}

void Nhan_vien::get(){
    cout<<"Nhan vien kiem ke: "; fflush(stdin); gets(Tennv);
    cout<<"Chuc vu: "; fflush(stdin); gets(Chuc_vu);
}
void Nhan_vien::show(){
    cout<<setw(19)<<"Nhan vien kiem ke: "<<Tennv<<setw(30)<<"Chuc vu: "<<Chuc_vu<<endl;
}

void Phieu::get(){
    cout<<"Ma phieu: "; fflush(stdin); gets(Ma_Phieu);
    cout<<"Ngay: "; fflush(stdin); gets(Ngay_Kiem);
    nv.get();
    p.get();
    cout<<"Nhap so luong tai san: "; cin>>n;
    x= new Taisan[n];
    for(int i=0;i<n;i++)
        x[i].get();
}
void Phieu::show() {
    int Tong_so_luong = 0;
    cout<<setw(10)<<"Ma phieu: "<<Ma_Phieu<<setw(54)<<"Ngay kiem ke: "<<Ngay_Kiem<<endl;
    nv.show();
    p.show();
    cout<<setw(15)<<"Ten tai san"<<setw(20)<<"So luong"<<setw(20)<<"Tinh trang"<<endl;
    for(int i=0;i<n;i++){
        x[i].show();
        Tong_so_luong += x[i].Soluong;
    }
    cout<<"So tai san da kiem ke: "<<n<<setw(20)<<"Tong so luong: "<<Tong_so_luong;
}

void Sua_Phieu(Phieu& a){
    for(int i=0;i<a.n;i++){
        if(strcmp("May vi tinh",a.x[i].Tents)==0){
            a.x[i].Soluong=20;
        }
    }
}

void Sap_xep(Phieu& a){
    for(int i=0;i<a.n-1;i++)
        for(int j=i+1;j<a.n;j++)
            if(a.x[i].Soluong>a.x[j].Soluong){
                Taisan b = a.x[i];
                a.x[i] = a.x[j];
                a.x[j] = b;
            }
}
//---------------------------------------------------------------
int main(){
    Phieu h;
    h.get();
    cout<<setw(50)<<"PHIEU KIEM TAI SAN\n\n";
    h.show();
    cout<<"\n\nSUA THONG TIN SO LUONG TAI SAN (MAY VI TINH)\n\n";
    Sua_Phieu(h);
    cout<<setw(50)<<"PHIEU KIEM TAI SAN\n\n";
    h.show();
    Sua_Phieu(h);
    cout<<"\n\nSAP XEP PHIEU THEO CHIEU TANG DAN CUA SO LUONG\n\n";
    Sap_xep(h);
    cout<<setw(50)<<"PHIEU KIEM TAI SAN\n\n";
    h.show();
}

//Input

/*PH01
1/1/2004
KIEU THI THANH
KE TOAN VIEN
TO CHUC HANH CHINH
PTC
HOANG BICH HAO
3
May vi tinh
5
Tot
May vi tinh
3
Het khau hao-hong
Ban lam viec
6
Tot
*/
