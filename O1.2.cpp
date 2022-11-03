#include<iostream>
#include<windows.h>
#include<iomanip>

using namespace std;

class MonHoc{
    private:
        char TenMon[12];
        double Diem;
        int Sotrinh;
    public:
        void get(int);
        void show();
        int getstrinh();
        char* getname();
        friend class Phieu;
};
class Phieu{
    private:
        char Masv[12],Tensv[12],Lop[20];
        int Khoa,n;
        MonHoc* x;
    public:
        void get();
        void show();
        ~Phieu(){
            delete [] x;
        }
        void mor_3_ST();
        void chen_them();
};
//-----------------------------------------------
void MonHoc::get(int i){
    cout<<"Mon "<<i<<endl;
    cout<<"Ten Mon: "; fflush(stdin);  gets(TenMon);
    cout<<"So trinh: "; cin>>Sotrinh;
    cout<<"Diem: "; cin>>Diem;
}
void MonHoc::show(){
    cout<<TenMon<<setw(20)<<Sotrinh<<setw(20)<<Diem<<endl;
}
int MonHoc::getstrinh(){
    return Sotrinh;
}
char *MonHoc::getname(){
    char* temp=new char[sizeof(TenMon)/sizeof(char)];
    temp=TenMon;
    return temp;
}

void Phieu::get(){
    cout<<"Ma sinh vien: "; fflush(stdin); gets(Masv);
    cout<<"Ten sinh vien: "; fflush(stdin); gets(Tensv);
    cout<<"Lop: "; fflush(stdin); gets(Lop);
    cout<<"Khoa: "; cin>>Khoa;
    cout<<"Nhap so luong mon: "; cin>>n;
    x = new MonHoc[n];
    for(int i=0;i<n;i++)
        x[i].get(i+1);
}
void Phieu::show(){
    double Tong_Diem=0, Tong_so_trinh=0;
    cout<<"Ma sinh vien: "<<Masv<<setw(50)<<"Ten sinh vien: "<<Tensv<<endl;
    cout<<"Lop: "<<Lop<<setw(50)<<"Khoa"<<Khoa<<endl;
    cout<<"Ten Mon"<<setw(20)<<"So trinh"<<setw(20)<<"Diem: "<<endl;
    for(int i=0;i<n;i++){
        Tong_so_trinh+=x[i].Sotrinh;
        Tong_Diem+=x[i].Diem;
        x[i].show();
    }
    cout<<setw(50)<<"Tong "<<(float)Tong_Diem/Tong_so_trinh;
}

void Phieu::mor_3_ST(){
    for(int i=0;i<n;i++){
        char* ans=x[i].getname();
        if(x[i].getstrinh()>3)
            i!=n-1?cout<<ans<<", ":cout<<ans<<endl;
        ans=NULL;
        delete [] ans;
    }
}

void Phieu::chen_them(){
    int k;
    cout<<"Nhap so luong mon hoc muon chen vao: ";  cin>>k;
    x=(MonHoc*)realloc(x,(n+k)*sizeof(MonHoc));
    for(int i=n;i<n+k;i++){
        x[i].get(i+1);
    }
    n=n+k;
}
//-----------------------------------------------

int main(){
    Phieu h;
    h.get();
    h.show();
    cout<<"\n---------------------------------------"<<endl;
    cout<<"Cac mon co tren 3 so trinh la: "<<endl;
    h.mor_3_ST();
    cout<<"\n---------------------------------------"<<endl;
    h.chen_them();
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
