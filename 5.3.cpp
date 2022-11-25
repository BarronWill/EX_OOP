#include<iostream>
#include<fstream>

using namespace std;

class TAMTHUC{
    float a, b, c;
    public:
        TAMTHUC();
        TAMTHUC(float x, float y, float z);
        TAMTHUC operator+(TAMTHUC y);
        TAMTHUC operator-(TAMTHUC y);
        TAMTHUC operator-();
    friend ostream& operator<<(ostream& x, const TAMTHUC& y);
};
TAMTHUC::TAMTHUC(): a(0), b(0), c(0)
    {}
TAMTHUC::TAMTHUC(float x, float y, float z): a(x), b(y), c(z)
    {}
TAMTHUC TAMTHUC::operator+(TAMTHUC y){
    TAMTHUC tempt;
    tempt.a=a+y.a;
    tempt.b=b+y.b;
    tempt.c=c+y.c;
    return tempt;
}
TAMTHUC TAMTHUC::operator-(TAMTHUC y){
    TAMTHUC tempt;
    tempt.a=a-y.a;
    tempt.b=b-y.b;
    tempt.c=c-y.c;
    return tempt;
}
TAMTHUC TAMTHUC::operator-(){
    a=-a;
    b=-b;
    c=-c;
    return *this;
}
ostream& operator<<(ostream& in, const TAMTHUC& y)
{
    in<<y.a<<" X"<<(char)253;
    if (y.b>=0) in<<" + "<<y.b<<" X ";
    else in<<" - "<<-y.b<<" X ";
    if(y.c>=0) in<<" + "<<y.c;
    else in<<" - "<<-y.c;
    return in;
}
int main(){
    TAMTHUC x(2,5,4), y(1,4,2);
    x=-x;y=-y;
    cout<<"Tam thuc x da dao dau: "<<x<<endl;
    cout<<"Tam thuc y da dao dau: "<<y<<endl;
    TAMTHUC T=x+y;
    TAMTHUC H=x-y;
    cout<<"Tam thuc TONG: "<<T<<endl;
    cout<<"Tam thuc HIEU: "<<H<<endl;
    return 0;
}