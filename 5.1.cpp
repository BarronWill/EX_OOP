#include<iostream>

using namespace std;

class Fraction{
    double a,b;
    public:
        Fraction operator - (Fraction);
        Fraction operator + (Fraction);
        Fraction operator * (Fraction);
        Fraction operator / (Fraction);
        double operator - ();
    friend istream& operator >> (istream& in, Fraction& fr);
    friend ostream& operator << (ostream& out, const Fraction& fr);
};
//------------------------------------------------------------------
Fraction Fraction::operator - (Fraction fr){
    Fraction tempt;
    tempt.a = a*fr.b - fr.a*b;
    tempt.b = b*fr.b;
    return tempt;
}
Fraction Fraction::operator + (Fraction fr){
    Fraction tempt;
    tempt.a = a*fr.b + fr.a*b;
    tempt.b = b*fr.b;
    return tempt;
}
Fraction Fraction::operator * (Fraction fr){
    Fraction tempt;
    tempt.a = a * fr.a;
    tempt.b = b * fr.b;
    return tempt;
}
Fraction Fraction::operator / (Fraction fr){
    Fraction tempt;
    tempt.a = a * fr.b;
    tempt.b = b * fr.a;
    return tempt;
}
double Fraction::operator - (){
    return a/b;
}
istream& operator >> (istream& in, Fraction& fr){
    cout<<"Nhap tu so: ";   cin>>fr.a;
    cout<<"Nhap mau so: ";  cin>>fr.b;
}
ostream& operator << (ostream& out, const Fraction& fr){
    out<<fr.a<<"/"<<fr.b;
    return out;
}

//---------------------------------------------------------
int main(){
    Fraction a, b, c;
    cout<<"Phan so thu 1"<<endl;  cin>>a;
    cout<<"Phan so thu 2"<<endl;  cin>>b;
    c = a + b;
    cout<<"Phep +: "<<-c<<endl;
    c = a - b;
    cout<<"Phep -: "<<-c<<endl;
    c = a * b;
    cout<<"Phep *: "<<-c<<endl;
    c = a / b;
    cout<<"Phep /: "<<-c<<endl;
}
