#include<iostream>
using namespace std;
int main(){
    const int size=10000;
    int m,n;
    int a[size][size],b[size][size];
    cin>>m>>n;
    int i,j;

    for(i=1;i<=m; i++)
    {
        for (j=1;j<=n;j++)
        {
         cin>>a[i][j];
        }
        
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++){
            cin>>b[i][j];
        }
    }
    for(i=1;i<=m;i++)
    {
        for (j=1;j<=n;j++)
        {
            cout<<" "<<a[i][j]+b[i][j]<<" ";
        }
        cout<<"\n";
    }
    
   return 0;  
}