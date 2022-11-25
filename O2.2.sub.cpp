#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>

using namespace std;

class Student;
class school{
    protected:
        char Name[20];
        char Date[15];
    friend class Faculty;
    friend void sua(Student& a);
};

class Person{
    private:
        char Name[20];
        char Birth[15];
        char Adress[20];
    public:
        Person();
        void Input();
        void Output();
};

class Faculty{
    private:
        char Name[20];
        char Date[15];
        school x;
    public:
        void input();
        void output();
    friend class Student;
    friend void sua(Student& a);
};

class Student : public Person{
    private:
        Faculty y;
        char Class[15];
        double score;
    public:
        Student();
        void input();
        void output();
    friend void sua(Student& a);
};
//---------------------------------

Person::Person(){
    strcpy(Name," ");
    strcpy(Birth," ");
    strcpy(Adress," ");
}
void Person::Input(){
    cout<<"Ten hoc sinh: "; fflush(stdin);  gets(Name);
    cout<<"Ngay sinh: ";    fflush(stdin);  gets(Birth);
    cout<<"Dia chi: ";  fflush(stdin);  gets(Adress);
}
void Person::Output(){
    cout<<"\nTen hoc sinh: "<<Name<<endl;
    cout<<"Ngay sinh: "<<Birth<<endl;
    cout<<"Dia chi: "<<Adress<<endl;
}

void Faculty::input(){
    cout<<"Ten nghanh: ";   fflush(stdin);  gets(Name);
    cout<<"Ngay gia nhap: "; fflush(stdin);  gets(Date);
    cout<<"Ten truong: ";   fflush(stdin);  gets(x.Name);
    cout<<"Ngay vao truong: "; fflush(stdin);  gets(x.Date);
}
void Faculty::output(){
    cout<<"Ten nghanh: "<<Name<<endl;
    cout<<"Ngay gia nhap: "<<Date<<endl;
    cout<<"Ten truong: "<<x.Name<<endl;
    cout<<"Ngay vao truong: "<<x.Date<<endl;
}

Student::Student(){
    strcpy(y.Name," ");
    strcpy(y.Date," ");
    strcpy(Class," ");
    score = 0;
}
void Student::input(){
    Person::Input();
    y.input();
    cout<<"Ten Lop: ";  fflush(stdin);  gets(Class);
    cout<<"Diem: "; cin>>score;
}
void Student::output(){
    Person::Output();
    y.output();
    cout<<"Ten Lop: "<<Class<<endl;
    cout<<"Diem: "<<score<<endl;
}

void sua(Student& a){
    strcpy(a.y.x.Name,"DHCNHN");
}

//-------------------------------------------
int main(){
    Student h;
    h.input();
    h.output();
    cout<<"\nSUA TEN TRUONG"<<endl;
    sua(h);
    h.output();
}
/*
Nguyen Van Viet
22-08-2003
An khanh
KHMT
22-03-2022
Haui
24-09-2021
KHMT01
6
*/
