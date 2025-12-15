#include<iostream>
#include<locale>
#include<string>
#include<codecvt>
#include<fstream>
#include<complex>
#include<cmath>
#include<limits>
using namespace std;
int main(){
    u32string str ( U"\U00004f60\U0000597d"); // ni hao 
    locale loc (locale(),new codecvt_utf8<char32_t>); // locale ?
    // locale loc (locale(),new codecvt_utf16<char32_t>); utf 16 
    basic_ofstream<char32_t> ofs ("test_1.txt");
    ofs.imbue(loc);
    cout << "Writing to file (UTF-8)" << endl;

    ofs << str;
    cout << "done!" << endl;
    cout << &str << endl; // Ox61fedc
    // wstring_convert <codecvt_utf8_utf16<char16_t>,<char16_t> converstion;
    // string mbs = converstion.to_bytes(u"\u4f60\u597d"); ni hao
    // cout << hex ;
    //for(int i=0; i<mbs.length();++i) cout << int(unsigned char(mbs[i])) << endl;
    // codecvt class
    // .in  // always_noconv
    // .out // encoding
    // unshift  //length // max_length
    //# complex
    complex<double> mycomplex (20.0,2.0);
    cout << "Imaginary part : " << mycomplex.imag() << endl; // rho * sin(theta);
    cout << "Realize   part : " << mycomplex.real() << endl;  //  rho * cos(theta);
    complex<double> mycomplex2 (3.0,4.0); // abs () is theory potagorus c^2 = a^2 + b^2
    cout << "value : " << mycomplex2 << " is :" << abs(mycomplex2) << " e*i :" <<  arg(mycomplex2) << " rad." << endl; // arg find angle
    cout << "norm is :" << norm(mycomplex2) << endl; // a**2 + b**2
    cout << "test : " << sqrt(norm(mycomplex2)) << endl; // sqrt
    cout << "+ : " << mycomplex2 << ", - :" << conj(mycomplex2) << endl; //
    cout << "imag :" << mycomplex2.imag() << ". real : " << mycomplex2.real() << ". \n";
    cout << polar(3,4) << endl; // polar ( rho , theta );
    complex<double> myprojection (numeric_limits<double>::infinity(),2.0);
    cout << "the projection of " << myprojection << " is " << proj(myprojection) << endl;



    return 0;
}