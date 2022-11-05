#include<iostream>
#include<windows.h>
#include<conio.h>
#include<iomanip>

using namespace std;

class SINHVIEN{
    private:
        char Masv[12];
        char Hoten[30];
        double DiemToan, DiemLy, DiemHoa;
    public:
        void Nhap();
        void Xuat();
        friend double TongDiem(SINHVIEN);
        friend void sapxep(SINHVIEN,int);
};

void SINHVIEN::Nhap(){
    cout<<"Ma sinh vien: "; fflush(stdin);  gets(Masv);
    cout<<"Ho ten: ";   fflush(stdin);  gets(Hoten);
    cout<<"Diem Toan: ";    cin>>DiemToan;
    cout<<"Diem Ly: ";  cin>>DiemLy;
    cout<<"Diem Hoa: "; cin>>DiemHoa;
}

void SINHVIEN::Xuat(){
    cout<<setw(15)<<Masv<<setw(20)<<Hoten<<setw(15);
    cout<<DiemToan<<setw(15)<<DiemLy<<setw(15)<<DiemHoa<<setw(15)<<TongDiem(*this)<<endl;
}

double TongDiem(SINHVIEN x){
    double Tong;
    Tong=x.DiemHoa + x.DiemToan + x.DiemLy;
    return Tong;
}
void sapxep(SINHVIEN* a, int n){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(TongDiem(a[i])>TongDiem(a[j])){
                SINHVIEN tempt = a[i];
                a[i] = a[j];
                a[j] = tempt;
            }
}
//--------------------------------------------------------
int main(){
    int n;
    cout<<"Nhap so luong sinh vien: ";  cin>>n;
    SINHVIEN* v = new SINHVIEN[n];
    for(int i=0;i<n;i++)
        v[i].Nhap();
    system("cls");
    cout<<"Sap xep"<<endl;
    cout<<setw(15)<<"Ma sinh vien"<<setw(15)<<"Ho ten"<<setw(20);
    cout<<"Diem Toan"<<setw(15)<<"Diem Ly"<<setw(15)<<"Diem Hoa"<<setw(15)<<"Tong Diem"<<endl;
    sapxep(v,n);
    for(int i=0;i<n;i++)
        v[i].Xuat();
    delete [] v;
}

//INPUT
/*
3
2022608149
Nguyen Anh Vu
8 8.2 8.8
2021608149
Nguyen Tu Duc
8.6 9 8.6
2021608150
Nguyen Van Viet
9.8 9.9 8.9
*/
