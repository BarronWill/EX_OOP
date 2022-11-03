#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class NSX{
    char Masx[12];
    char Tensx[12];
    char Dtnsx[12];
public:
    void Nhap();
    void Xuat();
};
class Hang{
    char Ma_Hang[12];
    char Ten_Hang[12];
    NSX x;
public:
    void Nhap();
    void Xuat();
};
//------------------------------------------------
void NSX::Nhap(){
    cout<<"Ma sx: "; fflush(stdin);   gets(Masx);
    cout<<"Ten hang: "; fflush(stdin);  gets(Tensx);
    cout<<"Dtnsx: "; fflush(stdin);   gets(Dtnsx);
}
void NSX::Xuat(){
    cout<<"Ma sx: "<<Masx<<endl;
    cout<<"Ten sx: "<<Tensx<<endl;
    cout<<"Dtnsx: "<<Dtnsx<<endl;
}

void Hang::Nhap(){
    cout<<"Ma hang: "; fflush(stdin);   gets(Ma_Hang);
    cout<<"Ten hang: "; fflush(stdin);  gets(Ten_Hang);
    x.Nhap();
}
void Hang::Xuat(){
    cout<<"Ma hang: "<<Ma_Hang<<endl;
    cout<<"Ten hang: "<<Ten_Hang<<endl;
    x.Xuat();
}
//------------------------------------------------
int main()
{
    Hang h;
    h.Nhap();
    h.Xuat();
}