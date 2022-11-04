#include<iostream>
#include<windows.h>
#include<iomanip>

using namespace std;

class Date{
    int D,M,Y;
    friend class Hang;
};

class Hang{
    private:
        char MaHang[12];
        char TenHang[30];
        Date Ngaysx;
    public:
        void Get(int);
        void Show(int);
        int MatHang_2017();
};

void Hang::Get(int i){
    cout<<"Hang so "<<i<<endl;
    cout<<"DD/MM/YYYY: "; cin>>Ngaysx.D>>Ngaysx.M>>Ngaysx.Y;
    cout<<"Ma Hang: ";  fflush(stdin);  gets(MaHang);
    cout<<"Ten Hang: "; fflush(stdin);  gets(TenHang);
}
void Hang::Show(int i){
    cout<<"Hang so "<<i<<endl;
    cout<<"Ngay san xuat: "<<Ngaysx.D<<"/"<<Ngaysx.M<<"/"<<Ngaysx.Y<<endl;
    cout<<"Ma Hang: "<<MaHang<<endl;
    cout<<"Ten Hang: "<<TenHang<<endl<<endl;
}
int Hang::MatHang_2017(){
    if(Ngaysx.Y==2017)
        return Ngaysx.Y;
    return 0;
}
//--------------------------------------------------------
int main(){
    int n;
    cout<<"Nhap so luong hang hoa: ";   cin>>n;
    Hang* h = new Hang[n];
    for(int i=0;i<n;i++)
        h[i].Get(i+1);
    system("cls");
    for(int i=0;i<n;i++)
        h[i].Show(i+1);
    cout<<"Nhung mat hang duoc san xuat vao nam 2017"<<endl;
    for(int i=0;i<n;i++)
        if(h[i].MatHang_2017()==2017)
            h[i].Show(i+1);
}

//INPUT
/*
3
20 08 2017
2017BTNHH
STYLUS PEN
22 08 2020
2020IPTNHH
IPAD
20 9 2019
2019BGTNHH
DESK
*/
