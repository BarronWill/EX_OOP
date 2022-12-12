#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

class phieu;
class khachhang{
private:
    char makh[15];
    char ten[20];
    char diachi[20];
    char chuadoan[15];
    char bacsike[20];
public:
    void nhap();
    void xuat();
friend void sua(phieu& obj);
};

class thuoc{
private:
    char tenhang[25];
    int soluong;
    int dongia;
public:
    void nhap();
    void xuat();
friend void sapxep(phieu& obj);
friend class phieu;
};

class phieu{
private:
    char maphieu[20];
    char ngaylap[15];
    khachhang kh;
    int n;
    thuoc* a;
public:
    void nhap();
    void xuat();
friend void sua(phieu& obj);
friend void sapxep(phieu& obj);
};

void khachhang::nhap(){
    cout<<"Ma khach hang: ";    fflush(stdin);  gets(makh);
    cout<<"Ten khach hang: ";   fflush(stdin);  gets(ten);
    cout<<"Dia chi: ";  fflush(stdin);  gets(diachi);
    cout<<"Chuan doan: ";   fflush(stdin);  gets(chuadoan);
    cout<<"Bac si ke don: ";    fflush(stdin);  gets(bacsike);
}
void khachhang::xuat(){
    cout<<"Ma KH: "<<setw(8)<<makh<<setw(20)<<"Ten khach: "<<ten<<endl;
    cout<<"Dia chi: "<<setw(8)<<diachi<<endl;
    cout<<"Chuan doan benh: "<<setw(28)<<chuadoan<<endl;
    cout<<"Bac si ke don: "<<setw(30)<<bacsike<<endl;
}

void thuoc::xuat(){
    cout<<setw(25)<<tenhang<<setw(15)<<soluong<<setw(15)<<dongia<<setw(15)<<soluong*dongia<<endl;
}
void thuoc::nhap(){
cout<<"Nhap ten hang: ";    fflush(stdin);  gets(tenhang);
cout<<"So luong: "; cin>>soluong;
cout<<"Don gia: ";  cin>>dongia;
}

void phieu::nhap(){
    cout<<"Ma phieu: "; fflush(stdin);  gets(maphieu);
    cout<<"Ngay lap: "; fflush(stdin);  gets(ngaylap);
    kh.nhap();
    cout<<"Nhap so luong thuoc: ";  cin>>n;
    a = new thuoc[n];
    for(int i=0;i<n;i++)
        a[i].nhap();
}
void phieu::xuat(){
    int tong = 0;
    cout<<setw(50)<<"PHIEU XUAT HANG\n\n";
    cout<<"Ma phieu: "<<setw(4)<<maphieu<<setw(20)<<"Ngay lap: "<<ngaylap<<endl;
    kh.xuat();
    cout<<"STT"<<setw(23)<<"TEN HANG"<<setw(15)<<"SO LUONG"<<setw(15)<<"DON GIA"<<setw(15)<<"THANH TIEN"<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1;
        a[i].xuat();
        tong+=a[i].dongia* a[i].soluong;
    }
    cout<<setw(65)<<"Tong cong tien: "<<tong;
}

void sua(phieu& obj){
    strcpy(obj.kh.ten, "Nguyen Huyen Trang");
}

void sapxep(phieu& obj){
    for(int i=0;i<obj.n-1;i++)
        for(int j=i+1;j<obj.n;j++)
        if(obj.a[i].soluong>obj.a[j].soluong){
            thuoc temp = obj.a[i];
            obj.a[i] = obj.a[j];
            obj.a[j] = temp;
        }
}

int main(){
    phieu a;
    a.nhap();
    a.xuat();
    sua(a);
    cout<<"\n\nSUA LAI THONG TIN KHACH HANG"<<endl;
    a.xuat();
    sapxep(a);
    cout<<"\n\nSAP XEP LAI DANH SACH THEO THU TU TANG DAN"<<endl;
    a.xuat();
}

/*PH01
10/04/2020
KH001
NGUYEN HONG HA
NAM DINH
TIM
NGUYEN THANH BINH
3
ASPIRIN 100MG
30
500
BRILINTA TAB 90MG
60
1700
NEBILET TAB 5MG 14'S
15
9000*/
