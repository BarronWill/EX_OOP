#include<iostream>
#include<windows.h>
#include<iomanip>

using namespace std;
class Hang;
class Date{
    int D,M,Y;
    friend int MatHang_2017(Hang x);
    friend class Hang;
};

class Hang{
    private:
        char MaHang[12];
        char TenHang[30];
        Date Ngaysx;
    public:
        void Get();
        void Show();
    friend int MatHang_2017(Hang x);
};

void Hang::Get(){
    cout<<"DD/MM/YYYY: "; cin>>Ngaysx.D>>Ngaysx.M>>Ngaysx.Y;
    cout<<"Ma Hang: ";  fflush(stdin);  gets(MaHang);
    cout<<"Ten Hang: "; fflush(stdin);  gets(TenHang);
}
void Hang::Show(){
    cout<<setw(8)<<Ngaysx.D<<"/"<<Ngaysx.M<<"/"<<Ngaysx.Y;
    cout<<setw(15)<<MaHang<<setw(15)<<TenHang<<endl;
}
int MatHang_2017(Hang x){
    if(x.Ngaysx.Y==2017)
        return x.Ngaysx.Y;
    return 0;
}
//--------------------------------------------------------
int main(){
    int n;
    cout<<"Nhap so luong hang hoa: ";   cin>>n;
    Hang* h = new Hang[n];
    for(int i=0;i<n;i++)
        h[i].Get();
    system("cls");
    cout<<setw(15)<<"Ngay san xuat"<<setw(15)<<"Ma Hang"<<setw(15)<<"Ten Hang"<<endl;
    for(int i=0;i<n;i++)
        h[i].Show();
    cout<<"\nNhung mat hang duoc san xuat vao nam 2017"<<endl;
    cout<<setw(15)<<"Ngay san xuat"<<setw(15)<<"Ma Hang"<<setw(15)<<"Ten Hang"<<endl;
    for(int i=0;i<n;i++)
        if(MatHang_2017(h[i])==2017)
            h[i].Show();
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
