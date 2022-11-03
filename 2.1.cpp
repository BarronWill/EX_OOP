#include<bits/stdc++.h>
using namespace std;

class Date{
private:
    int d,m,y;
public:
    void getter();
    void show();
};

class Human_resource{
private:
    char ID[12];
    char Name[20];
    Date HR;
public:
    void getter();
    void show();
};
//-------------------------------------------
void Date::getter(){
    cout<<"Day: "; cin>>d;
    cout<<"Month: "; cin>>m;
    cout<<"Year: ";cin>>y;
}
void Date::show(){
    cout<<"Day: "<<d<<"/"<<m<<"/"<<y;
}

void Human_resource::getter(){
    cout<<"ID: "; fflush(stdin); gets(ID);
    cout<<"Name: "; fflush(stdin); gets(Name);
    HR.getter();
}
void Human_resource::show(){
    cout<<"ID: "<<ID<<endl;
    cout<<"Name: "<<Name<<endl;
    HR.show();
}
//------------------------------------------------------
int main(){
    Human_resource h;
    h.getter();
    h.show();
}