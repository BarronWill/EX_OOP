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
        void Nhap(int);
        void Xuat(int);
        double TongDiem();
        friend void sapxep(SINHVIEN,int);
};

void SINHVIEN::Nhap(int i){
    cout<<"Sinh vien thu "<<i<<endl;
    cout<<"Ma sinh vien: "; fflush(stdin);  gets(Masv);
    cout<<"Ho ten: ";   fflush(stdin);  gets(Hoten);
    cout<<"Diem Toan: ";    cin>>DiemToan;
    cout<<"Diem Ly: ";  cin>>DiemLy;
    cout<<"Diem Hoa: "; cin>>DiemHoa;
}

void SINHVIEN::Xuat(int i){
    cout<<"Ma sinh vien: "<<Masv<<endl;
    cout<<"Ho ten: "<<Hoten<<endl;
    cout<<"Diem Toan: "<<DiemToan<<endl;
    cout<<"Diem Ly: "<<DiemLy<<endl;
    cout<<"Diem Hoa: "<<DiemHoa<<endl;
    cout<<"Tong Diem: "<<TongDiem()<<endl;
}

double SINHVIEN::TongDiem(){
    double Tong;
    Tong=DiemHoa + DiemToan + DiemLy;
    return Tong;
}
void sapxep(SINHVIEN* a, int n){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(a[i].TongDiem()>a[j].TongDiem())
                swap(a[i],a[j]);
}
//--------------------------------------------------------
int main(){
    int n;
    cout<<"Nhap so luong sinh vien: ";  cin>>n;
    SINHVIEN* v = new SINHVIEN[n];
    for(int i=0;i<n;i++)
        v[i].Nhap(i+1);
    system("cls");
    cout<<"Sap xep"<<endl;
    sapxep(v,n);
    for(int i=0;i<n;i++)
        v[i].Xuat(i);
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