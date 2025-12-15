#include<iostream>
#include<string.h>
#include<cctype>
using namespace std;
int main(){
    //const int size=100000;
    string s;
    cin >> s;
  bool has_upper = false; // เก็บว่า s มีตัวพิมพ์ใหญ่หรือไม่
  bool has_lower = false; // เก็บว่า s มีตัวพิมพ์เล็กหรือไม่
  for (char c: s) {
    if (isupper(c)) has_upper = true;
    if (islower(c)) has_lower = true;
  }
  if (has_upper && has_lower) cout << "Mix";
  else if (has_upper) cout << "All Capital Letter";
  else cout << "All Small Letter";
}
    /*int i;
    const int size=100000;
    char a[size];
    cin>>a[size];
    int m=strlen(a);
    bool up,down = false;
    for (i=0;i<m; i++)
    {
        if(isupper(a[i])){
            up=true;
        }
        if(islower(a[i])){
            down=true;
        }
    }
    if(up == true && down == false){
        cout<<"All Capital Letter";
    }
    else if(up == false && down == true){
        cout<<"All Small Letter";
    }
    else if(up== true && down == true ){
        cout<<"Mix";
    }
    
    /*
    for (int i=0;i<m; i++)
    {
        if(isupper(a[i])){
            up++;
        }
        if(islower(a[i])){
            down++;
        }
    }
    cout<<up<<"\n"<<down;
    for (int i= 1;i<=m; i++)
    {
        if(islower(a[i])){
            down++;
        }
    }
    if(up > 0 && down == 0)
    {
        cout<<"All Capital letter";
    }
    else if(up ==0 && down > 0)
    {
        cout<<"All Small Letter";
    }
    else if(up !=0  && down !=0)
    {
            cout<<"Mix";
    }   
   */




  /*
  const int size=20000;
  char s[size];
  cin>>s;
  int i;
  bool up,down= false;
  int m=strlen(s);
  for(int i;i<m;i++){
      if(isupper(i)) up = true;
      if(islower(i)) down = true;
  }
    if(up && down ) cout<<"Mix";
    else if(up) cout<<"All Capital Letter";
    else cout<<"All Small Letter";
    */