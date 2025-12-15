#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
class add{
    public:
        say(int c){ cout << c ; return c;}
    private:
        int c;
};
class Player_{
   
};
int function_asm(void){
    int res;
    /*
    asm code = 1
    use fuction to write asseembly code in c is "asm("1"); or __asm__("1");"

    */
    __asm__( 
        "movl $20,%%eax;"
        "movl $10,%%ebx;"
        "subl %%ebx,%%eax":"=a"(res)
    );
    cout << res << endl;

    return 0;
}
int add(int x,int y){
    return x+y;
}
auto add_2(int x,int y) -> int{
    return (x+y);
}
int function_auto(){
    // auto is automatic type 
    // auto d = {1.0} == double , float
    // auto d = {"c"} == char ,
    /*  auto d = "hello world" == string
    example:
        auto c; declaration auto
        cin << c ;
        cout << int,float,double,long long,char,string
    */
   // function auto add(int a,int b) ->int;
   // functon void is: auto add() ->void;
   // function string is : auto generateString(const std::string &s, int start , int len) -> std::string;
   //auto sum{ add(5,6) }; // 11
    add_2(5,5);
   return 0;
}
int function_enum(){
    /*
     *  คือ การประกาศตัวแปร เฉยๆ  
     *  มีการกำหนด ค่า ที่ ตายตัว
     *  และสามารถเรียงลำดับได้
     * เป็นคำเฉพาะ
     *
     */
}
int function_export(){
    /**
     * export เป้นการเปิดเพื่อใช้ร่วมกับ moudule
     *  เพื่อให้่สามาตรถเรียกไฟล์นั้น และ ฟังชันนั้นได้ เช่น
     * export int a(){}
     * พอเราเรียกจากไฟล์อื่น ก็ สามารถ import ชื่อ 
     * และ เรียก a() ได้ เลย
     */
}
int function_explicit(){
    /**
     * explicit เป็นการเรียกใช้เพื่อ ลดความซับซ้อนของฟังชัน
     *  เช่น ส่วนมากจะใช้ ใน class หรือ namespace
     *  a::explicit int add(int x,int y){};
     *  a a1(1,2);
     */
}
class B{
    public:
        void Show_exp();
        friend int Change_on(int a);
        auto Skip_i(int a)->string{};
    private:
        int a;    
};
int Change_on(int x){ // ใช้ร่วมกันได้
    cout << x << endl;
    return 0;
}
int function_friend(){
    /**
     *  คือ การ ยืม ใช้เพื่อ ทำงานร่วมกับ class | namespace | function | ที่ มี private ไว้อยุ่
     *  หรือ ไม่ได้อยุ่ ใน class เดียวกัน ถ้า ประกาศ friend จะสามารถใช้ร่วมกับ function นอกจาก class ได้
     */
    
}
int function_goto_loop(){
    
    loop: cout << "\n";
    cout << "1" << endl;
    cout << "2" << endl;
    cout << "3" << endl;
    int a=0;
    cin >> a ;
    if(a !=0){
        goto loop;
    }else{
        return 0;
    }

}
inline int cube(int s){
    return s*s*s;
}
int function_inline(){
    /**
     *  inline function 
     *  ใช้ ตอนที่ เรา ใช้ ฟังชั้น นั้นบ่อยเกินไป จะสามารถเรียกใช้ได้สะดวก แต่ จะมีประสิทธิภาพ ตอนที่ เราเรียกใช้บ่อยๆ
     * อย่างใน เกม ระบบ สุม่ของ อะไรทำนองนี้
     */
    cout << "The Cude of 3 is:" << cube(3) << endl;
    return 0;
}
int function_mutable(){
    /**
     *  mutable type ?? ;
     * mutable int y มัน fixed ว่าไม่มีค่าอะไร เปลี่ยนแปลงได้ตลอด นอกฟังชัน
     * 
     */
   
   // mutable int yw=0;

    return 0;
}
#include<typeinfo>
template<typename T>
T max(T arg1, T arg2){
    cout << typeid( T ).name() << "s compared." << endl;
    return ( arg1 > arg2 ? arg1 : arg2 );
    /**
     * Check ประเภท
     *  ที่ สร้างมามีที่มายังไง
     */
}
/**
 * using ไว้ใช้ การเรียก namespace อื่นๆ ที่เกี่ยวข้อง 
 *  และ ใช้ร่วมกับ template ได้
 * virtual ถ้่าไม่มีการประกาศคลาส จะเริ่มใช้ตัวอ้างอืงแต่ตอนแรก
 * ถ้ามีการประกาศ จะนำตัวที่อ้างอิงตัวล่าสุด และฟังชัน ใช้ซ้ำกันได้
 * class base {
public:
    void fun_1() { cout << "base-1\n"; }
    virtual void fun_2() { cout << "base-2\n"; }
    virtual void fun_3() { cout << "base-3\n"; }
    virtual void fun_4() { cout << "base-4\n"; }
};
 
class derived : public base {
public:
    void fun_1() { cout << "derived-1\n"; }
    void fun_2() { cout << "derived-2\n"; }
    void fun_4(int x) { cout << "derived-4\n"; }
};
 */
/*
    volatile int a; //
    ไม่สามารถลบได้่ ไม่สามารถ register ได้
    ไม่ได้สามารถเปลี่ยนได้
*/
int main(){
    cout << "Start" << endl;

    //function_asm();
    //function_auto();
    //printf("Hello World \n"); 
    //int abc;
    //scanf("%d",&abc);
    //abc <<= 0;
    //cout << abc << endl;
    srand(1000);
    int j = rand();
    cout << j << endl;
    
    
    return 0;
}
