#include<iostream>
#include<windows.h>
using namespace std;

class QuanLy{
    private:
        char Maql[12];
        char Hoten[12];
    public:
        void get();
        void show();
};

class May{
    private:
        char MaMay[12];
        char KieuMay[12];
        char TinhTrang[12];
    public:
        void get();
        void show();
};

class PhongMay{
    private:
        char Maphong[12];
        char Tenphong[12];
        double Dientich;
        QuanLy x;
        May* y;
        int n;
    public:
        void get();
        void show();
        ~PhongMay(){
            delete [] y;
        }
};
//----------------------------------------------
void QuanLy::get(){
    cout<<"Ma quan ly: "; fflush(stdin);   gets(Maql);
    cout<<"Ho ten: "; fflush(stdin);   gets(Hoten);
}
void QuanLy::show(){
    cout<<"Ma quan ly: "<<Maql<<endl;
    cout<<"Ho ten: "<<Hoten<<endl;
}

void May::get(){
    cout<<"Ma may: "; fflush(stdin);   gets(MaMay);
    cout<<"Kieu may: "; fflush(stdin);   gets(KieuMay);
    cout<<"Tinh trang: "; fflush(stdin);   gets(TinhTrang);
}
void May::show(){
    cout<<"Ma may: "<<MaMay<<endl;
    cout<<"Kieu may: "<<KieuMay<<endl;
    cout<<"Tinh trang: "<<TinhTrang<<endl;
}

void PhongMay::get(){
    x.get();
    cout<<"Ma phong: "; fflush(stdin);   gets(Maphong);
    cout<<"Ten phong: "; fflush(stdin);   gets(Tenphong);
    cout<<"Dien tich: "; cin>>Dientich;
    cout<<"Nhap so luong may: ";    cin>>n;
    y= new May[n];
    for(int i=0;i<n;i++)
        y[i].get();
    system("pause");
}
void PhongMay::show(){
    x.show();
    cout<<"Ma phong: "<<Maphong<<endl;
    cout<<"Ten phong: "<<Tenphong<<endl;
    cout<<"Dien Tich: "<<Dientich<<endl;
    for(int i=0;i<n;i++)
        y[i].show();
}
//---------------------------------------------
int main(){
    PhongMay h;
    h.get();
    h.show();
}
