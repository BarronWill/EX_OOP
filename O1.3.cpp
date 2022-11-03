#include<iostream>
#include<windows.h>
#include<conio.h>
#include<iomanip>
using namespace std;

class Taisan{
    private:
        char Tents[30],Tinh_trang[30];
        int Soluong;
    public:
        void get();
        void show() const;
        friend class Phieu;
};

class Phieu{
    private:
        char MaPhieu[12],Ngay[12];
        char TenNhanVien[20],Chuc_Vu[30];
        char Phong[30],Mphong[12];
        char Ten_truong_phong[20];
        Taisan* x;
        int n;
    public:
        void get();
        void show();
        int Tong_so_luong();
        void Sua();
        void sapxep();
};

void Taisan::get(){
    cout<<"Ten tai san: "; fflush(stdin); gets(Tents);
    cout<<"So luong: "; cin>>Soluong;
    cout<<"Tinh trang: "; fflush(stdin); gets(Tinh_trang);
}
void Taisan::show() const{
    cout<<Tents<<setw(20)<<Soluong<<setw(20)<<Tinh_trang<<endl;
}

void Phieu::get(){
    cout<<"Ma phieu: "; fflush(stdin); gets(MaPhieu);
    cout<<"Ngay: "; fflush(stdin); gets(Ngay);
    cout<<"Nhan vien kiem ke: "; fflush(stdin); gets(TenNhanVien);
    cout<<"Chuc vu: "; fflush(stdin); gets(Chuc_Vu);
    cout<<"Kiem ke tai phong: "; fflush(stdin); gets(Phong);
    cout<<"Ma phong: "; fflush(stdin); gets(Mphong);
    cout<<"Truong phong: "; fflush(stdin); gets(Ten_truong_phong);
    cout<<"Nhap so luong tai san: "; cin>>n;
    x= new Taisan[n];
    for(int i=0;i<n;i++)
        x[i].get();
}
int Phieu::Tong_so_luong(){
    int Tong=0;
    for(int i=0;i<n;i++){
        Tong+=x[i].Soluong;
    }
    return Tong;
}
void Phieu::Sua(){
    for(int i=0;i<n;i++){
        if(strcmp("May vi tinh",x[i].Tents)==0){
            x[i].Soluong=20;
        }
    }
}
void Phieu::sapxep(){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(x[i].Soluong>x[j].Soluong)
                swap(x[i],x[j]);
}
void Phieu::show() {
    cout<<"Ma phieu: "<<MaPhieu<<setw(20)<<"Ngay kiem ke: "<<Ngay<<endl;
    cout<<"Nhan vien kiem ke: "<<TenNhanVien<<setw(20)<<"Chuc vu: "<<Chuc_Vu<<endl;
    cout<<"Kiem ke tai phong: "<<Phong<<setw(20)<<"Ma phong: "<<Mphong<<endl;
    cout<<"Truong phong: "<<Ten_truong_phong<<endl;
    cout<<"Ten tai san"<<setw(20)<<"So luong"<<setw(20)<<"Tinh trang"<<endl;
    for(int i=0;i<n;i++)
        x[i].show();
    cout<<"So tai san da kiem ke: "<<n<<setw(20)<<"Tong so luong: "<<Tong_so_luong();
}

int main(){
    Phieu h;
    h.get();
    h.show();
    cout<<"\nSua thong tin so luong cua may vi tinh thanh 20"<<endl;
    h.Sua();
    h.show();
    cout<<"\nSap xep"<<endl;
    h.sapxep();
    h.show();
}

//Input

/*PH01
1/1/2004
KIEU THI THANH
KE TOAN VIEN
TO CHUC HANH CHINH
PTC
HOANG BICH HAO
3
May vi tinh
5
Tot
May vi tinh
3
Het khau hao-hong
Ban lam viec
6
Tot
*/