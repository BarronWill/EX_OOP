#include<iostream>
#include<string.h>

using namespace std;

class sach{
private:
    char tensach[25];
    char tentg[25];
    char tennsx[25];
    int sotrang;
public:
    sach();
    sach(char x[], char y[], char z[], int n);
    bool operator == (sach obj);
friend istream& operator >> (istream& in, sach& obj);
friend ostream& operator << (ostream& out, const sach& obj);
};

sach::sach(){
    strcpy(tensach,"");
    strcpy(tentg,"");
    strcpy(tennsx,"");
    sotrang = 0;
}
sach::sach(char x[], char y[], char z[], int n){
    strcpy(tensach,x);
    strcpy(tentg,y);
    strcpy(tennsx,z);
    sotrang = n;
}
bool sach::operator==(sach obj){
    if(strcmp(tensach, obj.tensach)==0&&strcmp(tentg, obj.tentg)==0&&sotrang==obj.sotrang)
        return true;
    return false;
}
istream& operator >> (istream& in, sach& obj){
    cout<<"Nhap ten sach: ";  fflush(stdin);  in.get(obj.tensach,25);
    cout<<"Nhap ten tac gia: "; fflush(stdin); in.get(obj.tentg,25);
    cout<<"Nhap ten nha san xuat: ";  fflush(stdin);  in.get(obj.tennsx,25);
    cout<<"Nhap so trang: ";    in>>obj.sotrang;
}
ostream& operator << (ostream& out, const sach& obj){
    out<<"Ten sach: "<<obj.tensach<<endl;
    out<<"Ten tac gia: "<<obj.tentg<<endl;
    out<<"Ten nha san xuat: "<<obj.tennsx<<endl;
    out<<"So trang: "<<obj.sotrang<<endl;
}

int main(){
    sach a("Good father","Mario Puzo","Alpha book",600), b("IT","Stephen King","Alpha Book",1024),c;
    cin>>c;
    if(a==c)    cout<<"2 sach giong nhau"<<endl;
    else cout<<"2 sach khac nhau"<<endl;
}
