#include<iostream>
#include<windows.h>
#include<iomanip>

using namespace std;
class Phieu;
class Sinh_vien{
    private:
        char Masv[12];
        char Tensv[20];
        char Lop[10];
        int Khoa;
    public:
        void get();
        void show();
};
class MonHoc{
    private:
        char TenMon[12];
        double Diem;
        int Sotrinh;
    public:
        void get();
        void show();
        friend class Phieu;
        friend void mor_3_ST(Phieu a);
};
class Phieu{
    private:
        int n;
        Sinh_vien y;
        MonHoc* x;
    public:
        void get();
        void show();
        ~Phieu(){
            x = NULL;
            delete [] x;
        }
    friend void mor_3_ST(Phieu a);
    friend void chen_them(Phieu& a);
};
//-----------------------------------------------
void MonHoc::get(){
    cout<<"Ten Mon: "; fflush(stdin);  gets(TenMon);
    cout<<"So trinh: "; cin>>Sotrinh;
    cout<<"Diem: "; cin>>Diem;
}
void MonHoc::show(){
    cout<<setw(15)<<TenMon<<setw(15)<<Sotrinh<<setw(15)<<Diem<<endl;
}

void Sinh_vien::get(){
    cout<<"Ma sinh vien: "; fflush(stdin); gets(Masv);
    cout<<"Ten sinh vien: "; fflush(stdin); gets(Tensv);
    cout<<"Lop: "; fflush(stdin); gets(Lop);
    cout<<"Khoa: "; cin>>Khoa;
}
void Sinh_vien::show(){

    cout<<setw(14)<<"Ma sinh vien: "<<Masv<<setw(50)<<"Ten sinh vien: "<<Tensv<<endl;
    cout<<setw(4)<<"Lop: "<<Lop<<setw(57)<<"Khoa: "<<Khoa<<endl;
}

void Phieu::get(){
    y.get();
    cout<<"Nhap so luong mon: "; cin>>n;
    x = new MonHoc[n];
    for(int i=0;i<n;i++){
        cout<<"Mon thu "<<i<<endl;
        x[i].get();
    }
}
void Phieu::show(){
    double Tong_Diem=0, Tong_so_trinh=0;
    cout<<setw(50)<<"PHIEU KIEM TAI SAN\n\n";
    y.show();
    cout<<setw(15)<<"Ten Mon"<<setw(15)<<"So trinh"<<setw(15)<<"Diem"<<endl;
    for(int i=0;i<n;i++){
        Tong_so_trinh+=x[i].Sotrinh;
        Tong_Diem+=x[i].Diem;
        x[i].show();
    }
    cout<<setw(44)<<"TB "<<fixed<<setprecision(2)
    <<(float)Tong_Diem/Tong_so_trinh;
}

void mor_3_ST(Phieu a){
    for(int i=0;i<a.n;i++){
        if(a.x[i].Sotrinh>3)
            i!=a.n-1?cout<<a.x[i].TenMon<<", ":cout<<a.x[i].TenMon<<endl;
    }
}

void chen_them(Phieu& a){
    int k;
    do{
    cout<<"Nhap vi tri muon chen: ";  cin>>k;
    k--;
    }while(k<=0||k>=a.n);
    a.x=(MonHoc*)realloc(a.x,(a.n+1)*sizeof(MonHoc));
    for(int i=a.n;i>k;i--){
        a.x[i] = a.x[i-1];
    }
        a.x[k].get();
    a.n++;
}
//-----------------------------------------------

int main(){
    Phieu h;
    h.get();
    h.show();
    cout<<"\n---------------------------------------"<<endl;
    cout<<"Cac mon co tren 3 so trinh la: "<<endl;
    mor_3_ST(h);
    cout<<"\n---------------------------------------"<<endl;
    chen_them(h);
    h.show();
}

//INPUT
/*
2021608149
Nguyen Viet
OOP
16
3
Toan roi rac
3
9
Kien truc may
5
9
Vat ly
6
9.8
*/
