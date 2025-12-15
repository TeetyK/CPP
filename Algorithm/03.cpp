#include<iostream>
//#define SIZE =1000000;
using namespace std;
int main(){
    const int SIZE=1000000;
    int M[SIZE];
    int m,i;
    cin>>m;
    for (i=1;i<=m;i++)
    {
        cin>>M[i];
    }
   long long int max=-2000000000;
   long long int min=20000000000;
    
    for (i=1;i<=m;i++)
    {
     if(M[i] >max){
         max=M[i];
     }    
    }
    for(i=1;i<=m;i++){
        if(M[i]<min){
            min=M[i];
        }
    }
    cout<<min<<"\n";
    cout<<max;
    return 0;
}