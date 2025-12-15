#include<iostream>
#include<algorithm>



using namespace std;

// การหาร หารด้วย 42 ไม่ทางที่ เสษจะมากกว่า 42
int main(){
    int A[10]={};// เก็บตัวแปร 10 ตัว
    int c_m[42]={}; // เก็บ เศษจากการหาร
    //cout << "Start:" << endl;
    for(int i =0;i<10;++i){

        cin >> A[i];
    int cou_sum = A[i] % 42;
        c_m[cou_sum] = 1; // ไม่มีการเปลี่ยนแปลง ค่า 
    }/*
   cout << 39 % 42 << endl;
   cout << 40 % 42 << endl;
   cout << 41 % 42 << endl;
   cout << 42 % 42 << endl;
   cout << 43 % 42 << endl;
   cout << 44 % 42 << endl;
   cout << 82 % 42 << endl;
   cout << 83 % 42 << endl;
   cout << 84 % 42 << endl;
   cout << 85 % 42 << endl;
    */
   int ans =0; // นับ เศษทั้งหมด
   for(int j =0;j<42;++j){
       if(c_m[j] ==1){
           ans +=1;
       }

   }

    cout << ans << endl;
    // รู้ใหม่ว่า จะหาร ตัวไรก็ตาม ตัวเศษไม่มีทางที่ค่าจะ เท่า หรือ มากกว่า ตัวหาร
    return 0;
}