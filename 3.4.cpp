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
        void Execute();
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
void Arg::Execute(){
    double delta,x1,x2;
    delta = pow(b,2) - 4*a*c;
    if(a==0)
        cout<<"Nghiem duy nhat cua phuong trinh la: "<<(double)-c/b<<endl;
    else  
        if(delta>0){
            x1=(double)(-b + sqrt(delta))/(2*a);
            x2=(double)(-b - sqrt(delta))/(2*a);
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
    a.Execute();
    cout<<"--------------------------"<<endl;
    b.Get();
    b.Show();
    b.Execute();
}