#include<iostream>
#include<fstream>
//#include<ofstream>
//#include<ifstream>

using namespace std;

int main(){
    // ios::trunc ถ้าหาก มีไฟล์อยุ่แล้่ว มันจะตัดแล้วสร้างใหม่
    // ios::ate เปิดไฟล์แล้ว ย้าย control
    // ios::app ย้าย output ต่อท้าย
    // ios::in อ่านไฟล์
    // ios::out เขียนไฟล์
    //ofstream outfile; // โหมด เขียน
    //outfile.open("text.txt",ios::out);
    char data[100];
    //outfile << data << endl;
    //outfile.close();
    /** File Position Pointers
     * istream -> seekg("seek get")
     * osteam -> seekp("seek put")
     * ios::beg <- defailt
     * ios:cur จุดเริ่ม
     * ios::end จุดจบ
     * fileObj.seek(n,ios::??);
     * fileObj.seek(0,ios::end); <-- end
     * 
     */
    ifstream inpfile; // โหมดอ่าน
    inpfile.open("text.txt",ios::in | ios::out);
    inpfile >> data;
    cout << data << endl;
    inpfile.close();

    return 0;
}