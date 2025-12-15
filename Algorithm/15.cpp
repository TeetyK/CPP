#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int jojo[3];
    int sum=0;
    for(int i=0;i<3;i++){ // ค่าห่างขอตัวเลข
        cin >> jojo[i];
    }
    for(int j=0;j<3;j++){
    if(jojo[0] > jojo[1]){
        swap(jojo[0],jojo[1]);
    }if(jojo[1]>jojo[2]){
        swap(jojo[1],jojo[2]);
    }if(jojo[0] > jojo[2]){
        swap(jojo[0],jojo[2]);
    }
    }
    /*for(int q=jojo[0];q<jojo[2];q++){
        if(q !=jojo[0] and q != jojo[1] and q !=jojo[2]){// 3 5 9
            sum +=1;                                    // 4 6 7 8
           // cout << sum << endl;
        }
    }*/
    int x,y;
    x =jojo[1]-jojo[0]-1; // 5-3-1 = 1
    y =jojo[2]-jojo[1]-1; // 9 - 5 -1 =3
    if(x>y){
        cout << x;
    }else{
        cout << y;
    }
    // j1 j2 j3
    // 3 5 9 หาพื้นที่เล่นได้นานที่สุด
    // 3 _ 5 _ _ _ 9
      // ระหว่าง 5 และ 9 เล่นได้นานสุด เลยตอบ 3
      /*    for 3 in 5: (2-1)
       *    for 5 in 9 (4-1)
       *    sum
       * 
       *  
       */
    //cout << (sum-1) ;
    
    return 0;
}