#include<iostream>
#include<windows.h>
#include<conio.h>
#include<iomanip>

using namespace std;

class NSX{
    char Mansx[20];
    char Tennsx[20];
    char DCNSX[30];
    friend class Hang;
};

class Hang{
    private:
        char MaHang[12];
        char TenHang[20];
        double Dongia, Trong_luong;
        NSX x;
    public:
        void Get();
        void Show();
};

void Hang::Get(){
    cout<<"Ma Hang: "; fflush(stdin);   gets(MaHang);
    cout<<"Ten Hang: "; fflush(stdin);  gets(TenHang);
    cout<<"Ma NSX: ";   fflush(stdin);  gets(x.Mansx);
    cout<<"Ten NSX: ";  fflush(stdin);  gets(x.Tennsx);
    cout<<"Dia chi: ";  fflush(stdin);  gets(x.DCNSX);
    cout<<"Gia Thanh: ";    cin>>Dongia;
    cout<<"Trong luong cua hang: "; cin>>Trong_luong;
    system("cls");
}

void Hang::Show(){
    cout<<"Ma Hang: "<<MaHang<<endl;
    cout<<"Ten Hang: "<<TenHang<<endl;
    cout<<"Ma NSX: "<<x.Mansx<<endl;
    cout<<"Ten NSX: "<<x.Tennsx<<endl;
    cout<<"Dia chi: "<<x.DCNSX<<endl;
    cout<<"Gia Thanh: "<<Dongia<<endl;
    cout<<"Trong luong cua hang: "<<Trong_luong<<"kg"<<endl;
}
//---------------------------------------------------------
int main(){
    Hang h;
    h.Get();
    h.Show();
}
//INPUT
/*
2022HH1
GIAO TRINH
22082016TNHH01
CTTNHH VAT TU GD
AN KHANH - HOAI DUC - HA NOI
50000 2.3
*/
