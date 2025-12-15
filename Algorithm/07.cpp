#include<iostream>
#include<stdio.h>
#include<math.h>
#include<iomanip> // setw(50) เว้น 50 , setfill()
using namespace std;
int main(){
    double r;
    double PI=M_PI;
    cin>>r;
    //cout<<PI*r*r<<endl;
    //cout<<2*r*r<<endl;
    printf("%.6lf\n%.6lf",PI*r*r,2*r*r);
    /*##################################################
    ###############Test C++ ############################ 
    ####################################################
    ####################################################
    */
    cout << "\n" << setprecision(7) << PI*r*r ;
    cout << "\n" << setfill('0') << setw(5) << 2*r*r << endl ; // เพิ่มเลขหน้า 
    cout << setprecision(5) << 2*r*r << endl;
    cout << fixed <<setprecision(5) << 2*r*r << endl; // เพิ่ม เลขหลัง

    return 0;
}