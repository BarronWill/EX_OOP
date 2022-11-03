#include<iostream>
#include<windows.h>
#include<iomanip>

using namespace std;

class HangHoa;
class Phieu{
    private:
        char MaPhieu[12];
        char NgayLap[12];
        char MaNCC[20];
        char Diachi[30];
        char TenNCC[12];
        int n;
        HangHoa* x;
    public:
        void get();
        void show();
        ~Phieu(){
            delete [] x;
        }
};

class HangHoa{
    private:
        char TenHangHoa[12];
        double DonGia;
        int Soluong;
    public:
        void get(int);
        void show();
        friend class Phieu;
};
//-----------------------------------------------
void HangHoa::get(int i){
    cout<<"Hang Hoa "<<i<<endl;
    cout<<"Ten Hang hoa: "; fflush(stdin);  gets(TenHangHoa);
    cout<<"Don Gia: "; cin>>DonGia;
    cout<<"So luong: "; cin>>Soluong;
}
void HangHoa::show(){
    cout<<TenHangHoa<<setw(20)<<DonGia<<setw(20)<<Soluong;
}

void Phieu::get(){
    cout<<"Ma phieu: "; fflush(stdin); gets(MaPhieu);
    cout<<"Ngay lap: "; fflush(stdin); gets(NgayLap);
    cout<<"Ma NCC: "; fflush(stdin); gets(MaNCC);
    cout<<"Ten NCC: "; fflush(stdin); gets(TenNCC);
    cout<<"Dia chi: "; fflush(stdin); gets(Diachi);
    cout<<"Nhap so cac mat hang: "; cin>>n;
    x = new HangHoa[n];
    for(int i=0;i<n;i++)
        x[i].get(i+1);
}
void Phieu::show(){
    double Tong=0, Thanh_Tien;
    cout<<"Ma phieu: "<<MaPhieu<<setw(50)<<"Ngay lap"<<NgayLap<<endl;
    cout<<"Ma NCC: "<<MaNCC<<setw(50)<<"Ma NCC: "<<TenNCC<<endl;
    cout<<"Dia chi: "<<Diachi<<endl;
    cout<<"Ten hang"<<setw(20)<<"Don gia"<<setw(20)<<"So luong"
    <<setw(20)<<"Thanh tien"<<endl;
    for(int i=0;i<n;i++){
        Thanh_Tien+=x[i].Soluong*x[i].DonGia;
        x[i].show();
        cout<<setw(20)<<Thanh_Tien<<endl;
        Tong+=Thanh_Tien;
    }
    cout<<setw(50)<<"Tong "<<Tong;
}
//-----------------------------------------------
int main(){
    Phieu h;
    h.get();
    h.show();
}
