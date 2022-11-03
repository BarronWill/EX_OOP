#include<iostream>
#include<windows.h>
using namespace std;

class Hang{
    private:
        char MaHang[12];
        char TenHang[12];
        int Dongia;
    public:
        void get();
        void show();
};

class Phieu{
    private:
        char MaPhieu[12];
        Hang* x;
        int n;
    public:
        void get();
        void show();
        ~Phieu(){
            delete [] x;
        }
};
//---------------------------------
void Hang::get(){
    cout<<"Ma hang: "; fflush(stdin);   gets(MaHang);
    cout<<"Ten hang: "; fflush(stdin);  gets(TenHang);
    cout<<"Don gia: "; cin>>Dongia;
}
void Hang::show(){
    cout<<"Ma hang: "<<MaHang<<endl;
    cout<<"Ten hang: "<<TenHang<<endl;
    cout<<"Don gia: "<<Dongia<<endl;
}

void Phieu::get(){
    cout<<"Ma phieu: "; fflush(stdin);   gets(MaPhieu);
    cout<<"Nhap so luong mat hang: ";   cin>>n;
    x= new Hang[n];
    for(int i=0;i<n;i++){
        x[i].get();
    system("pause");
    }
}
void Phieu::show(){
    cout<<"Ma phieu: "<<MaPhieu<<endl;
    for(int i=0;i<n;i++){
        x[i].show();
    }
}
//-----------------------------------
int main(){
    Phieu h;
    h.get();
    h.show();
}