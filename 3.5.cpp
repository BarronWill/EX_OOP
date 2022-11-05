#include<iostream>
#include<iomanip>
#include<windows.h>

using namespace std;

class Array{
    private:
        int* Value;
        int n;
    public:
        Array();
        Array(int);
        ~Array();
        void Get();
        void Show();
};

Array::Array():n(0)
    {}
Array::Array(int x){
    Value = new int[x];
    for(int i=0;i<x;i++)
        Value[i]=0;
    n=x;
}
Array::~Array(){
    delete [] Value;
    n=0;
}
void Array::Get(){
    cout<<"Nhap so luong gia tri: ";    cin>>n;
    Value = new int[n];
    for(int i=0;i<n;i++){
        cout<<"Nhap gia tri thu "<<i<<" :";
        cin>>Value[i];
    }
}
void Array::Show(){
    for(int i=0;i<n;i++)
        cout<<"Gia tri thu "<<i<<" :"<<Value[i]<<endl;
}
//-----------------------------------------------------
int main(){
    Array a(4),b;
    cout<<"Argument constructor"<<endl;
    a.Show();
    cout<<"Non-Argument constructor"<<endl;
    b.Get();
    b.Show();
}
