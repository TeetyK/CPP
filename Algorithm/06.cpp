#include<iostream>
#include<math.h>
#include<limits>
//#include<iomanip>
#include<stdio.h>
using namespace std;
int main(){
    double a,b; 
    scanf("%lf %lf",&a,&b);
    //cin>>a>>b;
    double c=pow(a,2)+pow(b,2);
    //float c=(a*a)+(b*b); //a*a b*b
    double total=sqrt(c);
    printf("%.6lf",total);
 // C=a+b || c^2 = a^2+b^2 



    return 0;
}