#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;


int main(){
    string name;
    cin >> name ;
    //count_name = strlen(name);
    int map_name[4] ={0 , 1 , 0 , 0}; // ผมจะแทน 1 เป้นตัวย้าย ตำแหน่งจะเป็น 0 1 2 3
    for(char i :name){
        if(i == 'A'){  // Check 
            swap(map_name[1],map_name[2]);
            
        }if(i == 'B'){
            swap(map_name[2],map_name[3]);
        }if(i == 'C'){
            swap(map_name[1],map_name[3]);
        }
        


    }
    for(int j =1; j<=3;j++){ // Check ว่า ไอ้ 1 เนี่ย มันอยุ่ ตรงไหน
        //cout << map_name[j] << " "; 
        if(map_name[j] == 1){ // ไล่ เช็คเอา ว่า มี เลข 1 ป่าว
            cout << j << endl ; // ถ้ามี จะปริ้นตำแหน่ง มัน
        }
    }
    //cout << "\n" ;
    /*
        if(map_name[1] = 1){ // ในส่วนของ output ที่โจทย์ ต้องการ
            cout << "1" ;
        }else if(map_name[2] = 1){
            cout << "2" ;
        }else if(map_name[3] = 1){
            cout << "3" ;
        }*/
// EASY ตรงไหนวะ 






    return 0; // จบการทำงาน พอละ
}