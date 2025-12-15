#include<iostream>
#include<exception>

using namespace std;

int main(){
    /**
     * มีไว้เพื่อ ป้องกัน โค็ดโดยเฉพาะ
     * จะมี throw คือ การโยนไปใน catch;
     * try คือ มันจะลองทำ cmd ที่อยุ่ในนั้น ถ้าหากมี error จะไปทำ ตรง catch()
     *  
     */
    
    int i=0;
    cin >> i ;
    try{
        if((int)i){ cout << "i is int" << endl; }
        
        else{ throw i; }
    }catch(int c){ cout << " input String " << endl; }
    


}