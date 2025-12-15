/**
 * @file class_object.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
// Overloading 
#include<iostream>
using namespace std;
class PrintData{
    public:
    void print(int i){cout << "Printing int:" << i << endl;}
    void print(double f){cout << "Printing float:" << f << endl;}
    void print(string c){cout << "Printing String:" << c << endl;}
    void print(char n){ cout << "Printing char:" << n << endl;}

};
//************************************************************************************************
//************************************************************************************************
//************************************************************************************************
//************************************************************************************************
//************************************************************************************************
//Operators Overloading in C++
//
class GAME{
    public:
        int get_num(void){ cout << a << "\n" << b << endl; return (a*b);}
        int set_num1(int num_1){ a = num_1; }
        int set_num2(int num_2){ b = num_2; }
        GAME operator+(const GAME& c){
             GAME gg; 
             gg.a = this->a + c.a;
             gg.b = this->b + c.b;
             return gg;
             }
        friend int Show_d();
    private:
        int a;
        int b;
};
int Show_d(){
    int d;
    string text_q = "D JingJing"; // <- 10 int
    d = text_q.length();
    return d;
}

int main(){
    PrintData pd;
    pd.print(1);
    pd.print(50.0);
    pd.print("HelloWorld!");
    GAME wq1;
    wq1.set_num1(10);
    wq1.set_num2(10);
    cout << wq1.get_num() << endl;
    GAME wq2;
    wq2.set_num1(10);
    wq2.set_num2(10);
    cout << wq2.get_num() << endl;
    GAME wq3;
    wq3 = wq1 + wq2;
    cout << wq3.get_num() << endl;
    cout <<  Show_d() << endl;

    return 0;
}