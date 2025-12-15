#include<iostream>
#include<ctime>
#include<cstring>
using namespace std;

int main(){
    //iostream
    int a;
    cin >> a ;
    cout << "Hi" << endl ;
    cerr << "Error" << a << endl; // บอก error
    clog << "Error" << a << endl; // บอก log 
    //ctime
    /**
     * time_t ให้ค่า หน่วย วินาทีมา
     * time() อ้างอิงเวลา
     * อย่าง เช่น time(&start) ก็ ตอนแรก พอ เราเรียกใช้อีกที จะเป็นอีกเวลาหนึ่ง ก็ time(&stop)
     * difftime(จุดสิ้นสุด,จุดเริ่มต้น) จะ diff เอาเวลาที่แตกกัน อย่าง เช่น difftime(&stop,&start); ก็คือ stop - start;
     * ctime(&??) คือ pointer ชี้ไปยังเวลา ปัจจุบันนี้ มันจะขึ้น วันอะไร เดือนไร วันที่เท่าไหร่ เวลากี่โมง นาที วินาที ปีอะไร
     * 
     */
    time_t now =time(0);
    char* dt =ctime(&now);
    cout << dt << endl;

    return 0;
}