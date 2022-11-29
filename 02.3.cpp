#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>

using namespace std;

class TruongDH;
class Khoa{
   private:
        char makhoa[15];
        char tenkhoa[15];
        char truongkhoa[20];
    friend class TruongDH;
    friend void Xoa(TruongDH& a);
};

class Ban{
    protected:
        char maban[15];
        char tenban[15];
        char ngaylap[15];
    friend class TruongDH;
};

class Truong{
    private:
        char matruong[15];
        char tentruong[15];
        char diachi[15];
    public:
        void Nhap();
        void Xuat();
};

class TruongDH: public Truong{
    private:
        Khoa* x;
        int n;
        Ban* y;
        int m;
    public:
        ~TruongDH(){
            delete [] x;
            delete [] y;
        }
        void Nhap();
        void Xuat();
    friend void Xoa(TruongDH& a);
};

//-----------------------------------------------
void Truong::Nhap(){
    cout<<"Ma truong: ";    fflush(stdin);  gets(matruong);
    cout<<"Ten truong: ";   fflush(stdin);  gets(tentruong);
    cout<<"Dia chi: ";  fflush(stdin);  gets(diachi);
}
void Truong::Xuat(){
    cout<<"Ma truong: "<<matruong<<endl;
    cout<<"Ten truong: "<<tentruong<<endl;
    cout<<"Dia chi: "<<diachi<<endl;
}

void TruongDH::Nhap(){
    Truong::Nhap();
    cout<<"Nhap so luong khoa: ";   cin>> n;
    x = new Khoa[n];
    for(int i = 0; i<n; i++){
        cout<<"Khoa "<<i+1<<endl;
        cout<<"Ma khoa: ";  fflush(stdin);  gets(x[i].makhoa);
        cout<<"Ten khoa: ";  fflush(stdin);  gets(x[i].tenkhoa);
        cout<<"Truong khoa: ";  fflush(stdin);  gets(x[i].truongkhoa);
    }
    cout<<"Nhap so luong ban: ";    cin>>m;
    y = new Ban[m];
    for(int i = 0; i<n; i++){
        cout<<"Ban "<<i+1<<endl;
        cout<<"Ma Ban: ";  fflush(stdin);  gets(y[i].maban);
        cout<<"Ten Ban: ";  fflush(stdin);  gets(y[i].tenban);
        cout<<"Ngay thanh lap: ";  fflush(stdin);  gets(y[i].ngaylap);
    }
}
void TruongDH::Xuat(){
    Truong::Xuat();
    for(int i=0; i<n; i++)
    {
    cout<<"Khoa thu "<<i+1<<endl;
    cout<<"Ma khoa: "<<x[i].makhoa<<endl;
    cout<<"Ten khoa: "<<x[i].tenkhoa<<endl;
    cout<<"Truong khoa: "<<x[i].truongkhoa<<endl<<endl;
    }
    for(int i=0; i<m; i++)
    {
    cout<<"Ban thu "<<i+1<<endl;
    cout<<"Ma ban: "<<y[i].maban<<endl;
    cout<<"Ten ban: "<<y[i].tenban<<endl;
    cout<<"Ngay TL: "<<y[i].ngaylap<<endl<<endl;
    }
}

void Xoa(TruongDH& a){
    for(int i=0; i<a.n; i++){
        if(strcmp(a.x[i].makhoa,"KH01") == 0)
                a.x[i] = a.x[i+1];
                a.n--;
        }
}

//--------------------------------------------------
int main(){
    TruongDH h;
    h.Nhap();
    h.Xuat();
    cout<<"\n\nXOA THONG TIN KHOA CO MA KH01 KHOI DANH SACH"<<endl;
    Xoa(h);
    h.Xuat();
}
/*
HAUI
CONG NGHIEP HA NOI
CAU DIEN
2
KH01
ABC
VA
KH02
BCD
VB
2
BN01
CDX
22/02/2002
BN02
CDC
22/09/2003
*/
