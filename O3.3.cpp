#include<iostream>

using namespace std;
template<class T>
class MATRIX{
    private:
        T a[100][100];
        int row, col;
    public:
        void Nhap();
        void Xuat();
        void CV();
};

template<class T>
void MATRIX<T>::Nhap(){
    cout<<"Nhap so luong hang: ";   cin>>row;
    cout<<"Nhap so luong cot: ";    cin>>col;
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++){
            cout<<"A["<<i+1<<"]["<<j+1<<"]: ";  cin>>a[i][j];
        }
}

template<class T>
void MATRIX<T>::Xuat(){
    cout<<"Ma tran"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

template<class T>
void MATRIX<T>::CV(){
    cout<<"Ma tran chuyen vi"<<endl;
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++)
                cout<<a[j][i]<<" ";
            cout<<endl;
        }
}

int main(){
    MATRIX<int> a;
    a.Nhap();
    a.Xuat();
    a.CV();
}
