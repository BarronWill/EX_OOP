#include<iostream>

using namespace std;

class TAMGIAC{
    private:
        double a, b, c;
    public:
        double operator - ();
    friend istream& operator >> (istream& in, TAMGIAC& x);
    friend ostream& operator << (ostream& out, TAMGIAC x);
};

double TAMGIAC::operator-(){
        return a+b+c;
}

istream& operator >> (istream& in, TAMGIAC& x){
    cout<<"Nhap cac so do lan luot a, b, c: ";  in>>x.a>>x.b>>x.c;
    return in;
}
ostream& operator << (ostream& out, TAMGIAC x){
    out<<"A: "<<x.a<<endl;
    out<<"B: "<<x.b<<endl;
    out<<"C: "<<x.c<<endl;
    out<<"Chu vi tam giac: "<<-x;
}

int main(){
    TAMGIAC a;
    cin>>a;
    cout<<a;
}