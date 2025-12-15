#include<iostream>
using namespace std;
int main(){
     int a,b,c;
    cin>>a>>b>>c;
    int total=a+b+c;
    /*
    if(total <=100 or total >=80){ cout << "A"; }
    else if(){}
    */
    if(total<=100){
        if (total >= 80 && total <= 100)
        {
            cout<<"A";
        }
        else if(total <= 79 && total >= 75)
        {
            cout<<"B+";

        }
        else if(total <=74 && total >=70)
        {
            cout<<"B";
        }
        else if(total <=69 && total >=65)
        {
            cout<<"C+";
        }
        else if(total <=64 && total >=60)
        {
            cout<<"C";
        }
        else if(total <=59 && total >=55)
        {
            cout<<"D+";
        }
        else if(total <=54 && total >=50)
        {
            cout<<"D";
        }
        else if(total <=49 && total >=0)
        {
            cout<<"F";
        }

    }
    else{
        cout<<"Error";
    }
   
}