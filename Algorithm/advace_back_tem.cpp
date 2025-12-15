#include<iostream>
using namespace std;

#define H_ "HelloWorld!"
#define MIN(a,b) ( ( (a)<(b) ) ? a : b)
#define DEBUG

#ifndef NULL
    #define NULL 0
#endif
#define MKSTR( x ) #x // # ตัวแปร
#define concet( q , p ) q##p //เชื่อมต่อ qp
int main(){

    int i = 100,j = 30;
    cout << MIN(i,j) << endl;
    cout << H_ << endl;
#ifdef DEBUG
    cerr << "HelloDev!" << endl;
#endif
#if 0
    cout << "Hi" << endl;
#endif
    cout << MKSTR("HuuMao") << endl;
    int qp=100;
    cout << concet(q,p);
    cout << __LINE__ << endl; // ตัว define macro default
    cout << __FILE__ << endl;
    cout << __DATE__ << endl;
    cout << __TIME__ << endl;
    return 0;
}