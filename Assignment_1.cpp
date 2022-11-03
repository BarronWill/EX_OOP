#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;

class Supplier{
   char Provider_code[30];
   char Name[30];
   char Address[100];
   char Phone_number[11];
public:
   void setter();
   void show();
   friend class Receipt;
};

class Product{
   char Product_code[30];
   char Product_name[30];
   int Quantity;
   int Unit_price;
public:
   void setter();
   void show();
   int Payment();
   friend class Receipt;
};

class Receipt{
   char Recept_code[30];
   char Date[30];
   int sl_hang;
   Supplier s;
   Product p[3];
public:
   void setter();
   void show();
   int less_80();
   void arrange();
};
//////////////////////////////////////////
void Supplier::setter(){
   cout<<"Ma nha cung cap: ";   cin.ignore();       gets(Provider_code);
   cout<<"Ten nha cung cap: ";                      gets(Name);
   cout<<"Dia chi: ";                               gets(Address);
   cout<<"SDT: ";                                   gets(Phone_number);
}
void Supplier::show(){
   cout<<"Ma nha cung cap: "<<Provider_code<<setw(52);
   cout<<"Ten nha cung cap: "<<Name<<endl;
   cout<<"Dia chi: "<<Address<<setw(31);
   cout<<"SDT: "<<Phone_number<<endl;
}

void Product::setter(){
   cout<<"Ma SP: ";    fflush(stdin);               gets(Product_code);
   cout<<"Ten san pham: ";                          gets(Product_name);
   cout<<"So luong: ";                              cin>>Quantity;
   cout<<"Don gia: ";                               cin>>Unit_price;
}
int Product::Payment(){
   return Quantity*Unit_price;
}
void Product::show(){
   cout<<Product_code;
   cout<<setw(25)<<Product_name;
   cout<<setw(25)<<Quantity;
   cout<<setw(25)<<Unit_price;
   cout<<setw(25)<<Payment()<<endl;
}

void Receipt::setter(){
   cout<<"Ma phieu: ";                              gets(Recept_code);
   cout<<"Ngay lap: ";                              gets(Date);
   s.setter();
   cout<<"So luong hang hoa: ";                     cin>>sl_hang;
   for(int i=0;i<sl_hang;i++){
      p[i].setter();
   }
   system("cls");
}
int Receipt::less_80(){
    int Times=0;
    for(int i=0;i<3;i++){
        if(p[i].Quantity<80)
            Times++;
    }
    return Times;
}
void Receipt::arrange(){
    for(int i=0;i<sl_hang-1;i++)
        for(int j=i+1;j<sl_hang;j++)
            if(p[i].Unit_price>p[j].Unit_price)
                swap(p[i],p[j]);
    }
void Receipt::show(){
   int Total_payment=0;
   cout<<"Victory University\n\n"<<endl;
   cout<<setw(50)<<"PHIEU NHAP VAN PHONG PHAM\n\n"<<endl;
   cout<<"Ma phieu: "<<Recept_code<<setw(50);
   cout<<"Ngay lap: "<<Date<<endl;
   s.show();
   cout<<endl;
   cout<<"Ma SP"<<setw(25)<<"Ten san pham"<<setw(25)<<"So luong"<<setw(25)<<"Don gia"<<setw(25)<<"Thanh tien"<<endl;
   for(int i=0;i<sl_hang;i++){
      p[i].show();
      Total_payment+=p[i].Payment();
   }
   cout<<endl<<setw(51)<<"TONG"<<setw(53)<<Total_payment<<endl<<endl;
   cout<<"Hieu truong"<<setw(51)<<"Phong tai chinh"<<setw(42)<<"Nguoi lap"<<endl<<endl;
}

///////////////////////////////////////////////////////////////////////
int main(){
   Receipt r;
   r.setter();
   r.show();
   cout<<"----------------------------------------------------------------------------------\n\n";
   cout<<"- Co "<<r.less_80()<<" san pham co so luong duoi 80\n\n";
   cout<<"- Sap xep mat hang theo gia tri don hang tang dan:\n\n";
   r.arrange();
   r.show();
}