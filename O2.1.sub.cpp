#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>

using namespace std;

class NSX{
    private:
        char TenNSX[20];
        char Diachi[20];
    public:
        void Nhap();
        void Xuat();
    friend class Hang;
};

class Hang{
    private:
        char Tenhang[20];
        NSX x;
        int Dongia;
    public:
        void Nhap();
        void Xuat();
        Hang();
};

class Date{
    private:
        int D,M,Y;
    public:
        void Nhap();
        void Xuat();
    friend class TIVI;
};

class TIVI : public Hang{
    private:
        double Kichthuoc;
        Date NgayNhap;
    public:
        void Nhap();
        void Xuat();
        TIVI();
};
//----------------------------------------------------
void Date::Nhap(){
    cout<<"DD/MM/YYYY: ";   cin>>D>>M>>Y;
}
void Date::Xuat(){
    cout<<"Ngay mua: "<<D<<"/"<<M<<"/"<<Y<<endl;
}

void NSX::Nhap(){
    cout<<"Ten nsx: ";  fflush(stdin);  gets(TenNSX);
    cout<<"Dia chi: ";  fflush(stdin);  gets(Diachi);
}
void NSX::Xuat(){
    cout<<"Ten nsx: "<<TenNSX<<endl;
    cout<<"Dia chi: "<<Diachi<<endl;
}

Hang::Hang(){
    strcpy(Tenhang,"");
    Dongia = 0;
    strcpy(x.TenNSX, "");
    strcpy(x.Diachi, "");
}
void Hang::Nhap(){
    cout<<"Ten Hang: "; fflush(stdin);  gets(Tenhang);
    x.Nhap();
    cout<<"Dong gia: "; cin>>Dongia;
}
void Hang::Xuat(){
    cout<<"\nTen Hang: "<<Tenhang<<endl;
    x.Xuat();
    cout<<"Dong gia: "<<Dongia<<" VND"<<endl;
}

TIVI::TIVI(){
    Kichthuoc = 0;
    NgayNhap.D = 0, NgayNhap.M = 0, NgayNhap.Y = 0;
}
void TIVI::Nhap(){
    Hang::Nhap();
    cout<<"Kich thuoc: ";   cin>>Kichthuoc;
    NgayNhap.Nhap();
}
void TIVI::Xuat(){
    Hang::Xuat();
    cout<<"Kich thuoc: "<<Kichthuoc<<"cm"<<endl;
    NgayNhap.Xuat();
}

//-------------------------------------------
int main(){
    TIVI h;
    h.Nhap();
    h.Xuat();
}

/*
Tivi
Shoppe
An Khanh
24000000
10
3 5 2022
*/
