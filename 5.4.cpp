#include<iostream>
#include<fstream>

using namespace std;

class MATRIX{
    int n, m;
    double **a;
    public:
        ~MATRIX();
        MATRIX operator+(MATRIX y);
        MATRIX operator-(MATRIX y);
        MATRIX operator-();
    friend ostream& operator<<(ostream& in, const MATRIX& y);
    friend istream& operator>>(istream& out, MATRIX& y);
};

//----------------------------------------------------------------
MATRIX::~MATRIX(){
    for(int i= 0; i<m; i++)
        delete [] a[i];
    delete [] a;
}
istream& operator>>(istream& in, MATRIX& y){
    cout<<"n="; in>>y.n;
    cout<<"m="; in>>y.m;
    y.a=new double*[y.n];
    for(int i=0; i<y.n; i++)
        y.a[i]=new double[y.m];
    for(int i=0; i<y.n; i++)
        for(int j=0; j<y.m; j++){
            cout<<"a["<<i<<"]["<<j<<"]=";
            in>>y.a[i][j];
        }
    return in;
}
ostream& operator<<(ostream& in, const MATRIX& y){
    for(int i=0; i<y.n; i++){
        for(int j=0; j<y.m; j++)
            in<<y.a[i][j]<<" ";
        in<<endl;
    }
    return in;
}
MATRIX MATRIX::operator + (MATRIX y){
    MATRIX tempt;
    if(m==y.m && n==y.n){
        tempt.n=n; tempt.m=m;
        tempt.a=new double*[n];
        for(int i=0; i<n; i++)
            tempt.a[i]=new double[m];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                tempt.a[i][j]=a[i][j]+y.a[i][j];
    }
    else{
        cout<<"Hai ma tran khong cung kich thuoc !"<<endl;
        tempt.n=tempt.m=0;
    }
    return tempt;
}
MATRIX MATRIX::operator - (MATRIX y){
    MATRIX tempt;
    if(m==y.m && n==y.n){
        tempt.n=n; tempt.m=m;
        tempt.a=new double*[n];
        for(int i=0; i<n; i++)
            tempt.a[i]=new double[m];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                tempt.a[i][j]=a[i][j]-y.a[i][j];
    }
    else{
        cout<<"Hai ma tran khong cung kich thuoc !"<<endl;
        tempt.n=tempt.m=0;
    }
    return tempt;
}
MATRIX MATRIX::operator - (){
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            a[i][j]=-a[i][j];
    return *this;
}
//--------------------------------------------------
int main()
{
    MATRIX P, Q;
    cout<<"Nhap ma tran P:"<<endl;  cin>>P;
    cout<<"Nhap ma tran Q:"<<endl;  cin>>Q;
    P=-P; Q=-Q;
    cout<<"Ma tran da doi dau P:"<<endl;
    cout<<P;
    cout<<"Ma tran da doi dau Q:"<<endl;
    cout<<Q;
    MATRIX M = P+Q;
    MATRIX N = P-Q;
    cout<<"Ma tran tong: "<<endl;
    cout<<M;
    cout<<"Ma tran hieu: "<<endl;
    cout<<N;
}