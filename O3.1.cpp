#include<iostream>
#include<fstream>

using namespace std;

class Array{
    private:
        float a[100];
        int n;
    public:
        Array operator ++ ();
        Array operator -- ();
    friend istream& operator >> (istream& in, Array& a);
    friend ostream& operator << (ostream& out, const Array& a);
};

Array Array::operator++(){
    for(int i=0;i<n-1;i++)
        for(int j=i;j<n;j++)
            if(a[i]>a[j]){
                    int tempt = a[i];
                    a[i] = a[j];
                    a[j] = tempt;
            }
}
Array Array::operator -- (){
    for(int i=0;i<n-1;i++)
        for(int j=i;j<n;j++)
            if(a[i]<a[j])
                {
                    int tempt = a[i];
                    a[i] = a[j];
                    a[j] = tempt;
                }
}

istream& operator >> (istream& in, Array& x){
    cout<<"Nhap so luong phan tu: ";    cin>>x.n;
    for(int i=0;i<x.n;i++){
        cout<<"Nhap A["<<i+1<<"]: ";    in>>x.a[i];
    }
    return in;

}

ostream& operator << (ostream& out, const Array& y){
    for(int i=0;i<y.n;i++){
        out<<"A["<<i+1<<"]: "<<y.a[i]<<endl;
    }
    return out;
}

int main(){
    fstream file("file.txt", ios::out);
    Array a;
    cin>>a;
    cout<<"SAP XEP MANG THEO CHIEU TANG DAN"<<endl; ++a;
    file<<"SAP XEP MANG THEO CHIEU TANG DAN"<<endl;
    file<<a;    cout<<a;
    cout<<"SAP XEP MANG THEO CHIEU GIAM DAN"<<endl; --a;
    file<<"SAP XEP MANG THEO CHIEU GIAM DAN"<<endl;
    file<<a;    cout<<a;
}
