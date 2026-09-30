#include <iostream>
using namespace std;
 class item {
    public:
   string name;
   double price;
    int quantity;
    item(string s,int q,double p){
        name=s;
        price=p;
        quantity=q;
    }
    void show(){
        cout<<name<<"    ";
        cout<<price<<"    ";
        cout<<quantity<<"     ";
    }
    int calculate(int &price){
         
    }

 };

 
