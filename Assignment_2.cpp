#include<iostream>
#include<iomanip>
#include<string.h>
#include<conio.h>
#include<windows.h>
using namespace std;
class  PERSON{
    char name[30];
    char birth[11];
    char hometown[30];
public:
    void get();
    void show();
};

class  STUDENT : public PERSON{
    char student_id[15];
    char Faculty[30];
    int course;
public:
    void get();
    void show();
    friend class CLASS;
};

class  CLASS{
    char class_id[15];
    char class_name[20];
    char date[10];
    STUDENT* x;
    int n;
    char teacher_name[20];
public:
    void get();
    void show();
    CLASS();
    CLASS(char[], char[], char[], char[]);
    ~CLASS(){
        delete [] x;
    }
    int Seach_K11();
    void Arranged_by_course();
};
//-----------------------------------------------------------
void STUDENT::get(){
    PERSON::get();
    cout<<"What's the name id of the student: "; fflush(stdin); gets(student_id);
    cout<<"What's his faculty: "; fflush(stdin); gets(Faculty);
    cout<<"How many courses does he have: "; cin>>course;
}
void STUDENT::show(){
    PERSON::show();
    cout<<setw(31)<<student_id<<setw(21)<<Faculty<<setw(6)<<course<<endl;
}

void PERSON::get(){
    cout<<"Name: "; fflush(stdin); gets(name);
    cout<<"Birth: "; fflush(stdin); gets(birth);
    cout<<"Home town: "; fflush(stdin); gets(hometown);
}
void PERSON::show(){
    cout<<name<<setw(14)<<birth<<setw(12)<<hometown;

}
CLASS::CLASS(){
    strcpy(class_id," ");
    strcpy(class_name," ");
    strcpy(date," ");
    strcpy(teacher_name," ");
}
CLASS::CLASS(char class_id[15], char class_name[20], char date[10], char teacher_name[20]){
    strcpy(this->class_id,class_id);
    strcpy(this->class_name,class_name);
    strcpy(this->date,date);
    strcpy(this->teacher_name,teacher_name);
}
void CLASS::get(){
    cout<<"The number of students: "; cin>>n;
    x=new STUDENT[n];
    for(int i=0;i<n;i++)    x[i].get();
}
int CLASS::Seach_K11(){
    int ans=0;
    for(int i=0;i<n;i++)
        if(x[i].course==11)
            ans++;
    return ans;
}
void CLASS::Arranged_by_course(){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(x[i].course>x[j].course)
                swap(x[i],x[j]);
}
void CLASS::show(){
    cout<<class_id<<setw(61)<<class_name<<endl;
    cout<<teacher_name<<setw(50)<<date<<endl;
    cout<<"Name"<<setw(20)<<"Birth"<<setw(20)<<"Home Town"<<setw(20);
    cout<<"ID"<<setw(20)<<"Faculty"<<setw(20)<<"Course"<<endl;
    for(int i=0;i<n;i++)
        x[i].show();

}
//--------------------------------------------------------
int main(){
    CLASS cl("20221IT6018002","Huong Doi Tuong","18/09/2022","Nguyen Thi Cam Ngoan");
    cl.get();
    system("cls");
    cl.show();
    cout<<"\nThe number of student of K11: "<<cl.Seach_K11()<<endl;
    cout<<"\nThe sorted array"<<endl;
    cl.Arranged_by_course();
    cl.show();
}
//INPUT MAU
/*
2
Nguyen Van Viet
22/08/2003
Ha Noi
2021608149
Computer Science
9
Nguyen Tu Duc  
31/01/1999
Ha Noi
2016608149
Auto-machine
11
*/