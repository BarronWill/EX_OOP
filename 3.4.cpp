#include<iostream>
#include<windows.h>
#include<iomanip>
#include<math.h>

using namespace std;

class Arg{
    private:
        double a,b,c;
    public:
        Arg();
        Arg(double, double, double);
        void Get();
        void Show();
    friend void Execute(Arg x);
};

Arg::Arg():a(0),b(0),c(0)
    {}
Arg::Arg(double x, double y, double z):a(x),b(y),c(z)
    {}
void Arg::Get(){
    cout<<"ax^2 + bx + c = 0"<<endl;
    cout<<"Nhap 3 he so a, b va c: ";   cin>>a>>b>>c;
}
void Arg::Show(){
    cout<<a<<"x^2 + "<<b<<"x + "<<c<<" = 0"<<endl;
}
void Execute(Arg x){
    double delta,x1,x2;
    delta = pow(x.b,2) - 4*x.a*x.c;
    if(x.a==0)
        cout<<"Nghiem duy nhat cua phuong trinh la: "<<(double)-x.c/x.b<<endl;
    else  
        if(delta>0){
            x1=(double)(-x.b + sqrt(delta))/(2*x.a);
            x2=(double)(-x.b - sqrt(delta))/(2*x.a);
            cout<<"Phuong trinh co 2 nghiem phan biet: "<<endl;
            cout<<"X1 = "<<x1<<endl;
            cout<<"X2 = "<<x2<<endl;
        }
        else
            cout<<"Phuong trinh vo nghiem";
}
//------------------------------------------------------
int main(){
    Arg a(3,-5,2),b;
    a.Show();
    Execute(a);
    cout<<"--------------------------"<<endl;
    b.Get();
    b.Show();
    Execute(b);
}
