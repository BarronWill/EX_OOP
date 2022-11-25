#include<iostream>
#include<stdio.h>

using namespace std;

class complex_num{
    int a, b;
    public:
        complex_num();
        complex_num(int a1, int b1);
        complex_num operator + (complex_num);
        complex_num operator - (complex_num);
    friend ostream& operator << (ostream& out, const complex_num& cn);
};
//-----------------------------------------------
complex_num::complex_num():a(0), b(0)
        {}
complex_num::complex_num(int a1, int b1):a(a1), b(b1)
        {}
complex_num complex_num::operator + (complex_num cn){
    complex_num tempt;
    tempt.a = a + cn.a;
    tempt.b = b + cn.b;
}
complex_num complex_num::operator-(complex_num cn){
    complex_num tempt;
    tempt.a = a - cn.a;
    tempt.b = b - cn.b;
}
ostream& operator << (ostream& out, const complex_num& cn){
    out<<cn.a<<" + i*"<<cn.b;
    return out;
}
//----------------------------------------------------------
int main(){
    complex_num cn1(3,4), cn2(5,6), cn3;
    cn3 = cn1 + cn2;
    cout<<"Phep +: "<<cn3<<endl;
    cn3 = cn1 - cn2;
    cout<<"Phep -: "<<cn3;
}
