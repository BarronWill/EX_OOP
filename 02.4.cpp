#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>

using namespace std;

class Benh_Vien;
class Benh_Nhan;

class Nguoi{
    protected:
        char ten[15];
        int tuoi;
    public:
        void nhap();
        void xuat();
    friend void mor_30(Benh_Nhan* a, int n);
};

class Benh_vien{
    protected:
        char tenvien[15];
        char diachi[15];
        Nguoi giamdoc;
    friend class Benh_Nhan;
};

class Benh_Nhan : public Nguoi{
    private:
        char ma[15];
        char tiensu[20];
        char chuandoan[15];
        Benh_vien x;
    public:
        void nhap();
        void xuat();
    friend void sua(Benh_Nhan* a, int n);
};
//-------------------------------------------------
void Nguoi::nhap(){
    cout<<"Ho ten: ";   fflush(stdin);  gets(ten);
    cout<<"Tuoi: "; cin>>tuoi;
}
void Nguoi::xuat(){
    cout<<"Ho ten: "<<ten<<endl;
    cout<<"Tuoi: "<<tuoi<<endl;
}

void Benh_Nhan::nhap(){
    cout<<"Ma: ";   fflush(stdin);  gets(ma);
    Nguoi::nhap();
    cout<<"Tien su: ";  fflush(stdin);  gets(tiensu);
    cout<<"Chuan doan: ";   fflush(stdin);  gets(chuandoan);
    cout<<"Benh vien"<<endl;
    cout<<"Ten benh vien: ";    fflush(stdin);  gets(x.tenvien);
    cout<<"Dia chi: ";  fflush(stdin);  gets(x.diachi);
    cout<<"Giam doc"<<endl;
    x.giamdoc.nhap();
}
void Benh_Nhan::xuat(){
    cout<<"\nMa: "<<ma<<endl;
    Nguoi::xuat();
    cout<<"Tien su: "<<tiensu<<endl;
    cout<<"Chuan doan: "<<chuandoan<<endl;
    cout<<"Benh vien"<<endl;
    cout<<"Ten benh vien: "<<x.tenvien<<endl;
    cout<<"Dia chi: "<<x.diachi<<endl;
    cout<<"Giam doc"<<endl;
    x.giamdoc.xuat();
}

void mor_30(Benh_Nhan* a, int n){
    int k = 0;
    for(int i=0; i<n; i++)
        if(a[i].tuoi>30)
            k++;
    cout<<"\n\nCO "<<k<<" BENH NHAN LON HON 30 TUOI"<<endl;
}

void sua(Benh_Nhan* a,int n){
    for(int i=0;i<n;i++)
        if(strcmp(a[i].ma, "BN01") == 0)
            a[i].tuoi = 20;
}
//-----------------------------------------------
int main(){
    int n;
    cout<<"Nhap so luong benh nhan: ";  cin>>n;
    Benh_Nhan* h = new Benh_Nhan[n];
    for(int i =0; i<n; i++){
        h[i].nhap();
    }
    for(int i =0; i<n; i++){
        h[i].xuat();
    }
    mor_30(h,n);
    cout<<"\n\nSUA TUOI BENH NHAN CO MA BN01 THANH 20 "<<endl;
    sua(h,n);
    for(int i =0; i<n; i++){
        h[i].xuat();
    }
    delete [] h;
}

/*
2
BN01
NGUYEN VIET
19
KHONG CO
BINH THUONG
BACH MAI
HA NOI
VAN A
50
BN02
NGUYEN DUC
31
KHONG CO
BINH THUONG
BACH MAI
HA NOI
VAN A
50
*/
