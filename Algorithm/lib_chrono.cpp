#include<iostream>
#include<ratio>
#include<chrono>
#include<ctime>

using namespace std;
int main(){
    
    typedef chrono::duration<int> seconds_type; 
    typedef chrono::duration<int,milli> milliseconds_type;
    typedef chrono::duration<int,ratio<60*60>> hours_type;
    hours_type h_oneday(24); // 24h
    seconds_type s_oneday (60*60*24); // 86400s
    milliseconds_type ms_oneday (s_oneday);
    // สามารถ ประกาศ ตัวแปร แบบ typedef ได้ และปกติ
    seconds_type s_onehour (60*60); //3600s / h
    cout << s_onehour.count() << endl;
    //using chrono::steady_clock;
    chrono::steady_clock::time_point t1 =chrono::steady_clock::now();
    cout << ". . . " << endl;
    chrono::steady_clock::time_point t2 =chrono::steady_clock::now();
    chrono::steady_clock::duration d = t2 - t1; // เวลาที่ใช้ไป
    if( d == chrono::steady_clock::duration::zero()) cout << "the internal clock didn't tick." << endl; // check chrono clock works 
    else cout << d.count() << endl;
    cout << "min :" << chrono::system_clock::duration::min().count() << endl;
    cout << "max :" << chrono::system_clock::duration::max().count() << endl;
    chrono::duration<int> foo; // 0
    chrono::duration<int> bar (10); // 10
    foo = bar;
    cout << boolalpha << "foo = bar :" << (foo == bar) << endl;
    cout << "foo :" << foo.count() << endl;
    cout << "bar :" << bar.count() << endl;
    //$$$$$$$$$$$$$$$$$$$$$$$
    chrono::system_clock::time_point ax = chrono::system_clock::now();
    chrono::system_clock::duration dtn = ax.time_since_epoch();
    cout << dtn.count() << endl;
    // สามารถ
    chrono::duration<int,ratio<1,3>> d1(1);// 1 tick of 1/3 second
    cout << d1.count() << endl;
    chrono::high_resolution_clock::time_point tt1 = chrono::high_resolution_clock::now();
    cout << "10 star * \n ";int i =0; do{ cout << "*"; i++; }while(i != 10);
    cout << endl;
    chrono::high_resolution_clock::time_point tt2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>> (tt2 - tt1);
    cout << time_span.count() << " seconds." << endl;
    chrono::steady_clock::time_point tt3 = chrono::steady_clock::now();
    cout << "Hi" << endl; 
    chrono::steady_clock::time_point tt4 = chrono::steady_clock::now();
    chrono::duration<double> timing1 = chrono::duration_cast<chrono::duration<double>> (tt4 - tt3);
    cout << "Time use be is : " << timing1.count() << " seconds." << endl;
    ///////////////////////////////
    chrono::duration<int,ratio<60*60*24>> one_day (1);
    chrono::system_clock::time_point today_1 = chrono::system_clock::now();
    chrono::system_clock::time_point tomoo_1 = today_1 + one_day;
    time_t time_now = chrono::system_clock::to_time_t (today_1);
    cout << "today is : " << ctime(&time_now) << endl;
    time_now = chrono::system_clock::to_time_t (tomoo_1);
    cout << "tomorrow is :" << ctime(&time_now) << endl;
    tm timeinfo = tm();
    timeinfo.tm_year = 100; // defalut is : 1900 // if plus 100 equel to 2000;
    timeinfo.tm_mon = 6; // July
    timeinfo.tm_mday = 1;
    time_t event_boss1 =  mktime(&timeinfo);
    chrono::system_clock::time_point tp1 = chrono::system_clock::from_time_t (event_boss1);
    chrono::system_clock::duration dcommu = chrono::system_clock::now() - tp1 ; // ระยะเวลาที่ผ่านมา
    typedef chrono::duration<int,ratio<60*60*24>> days_types;
    days_types ndays = chrono::duration_cast<days_types> (dcommu); // เอาระยะเวลาที่ห่าง มาแสดงเป็นวัน ที่ห่างไปแล้วกี่วัน
    cout << ndays.count() << " days." << endl;
    /////////
    chrono::seconds s (1);
    chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds> (s); // 1
    ms += chrono::milliseconds(2500); // 3500
    s = chrono::duration_cast<chrono::seconds> (ms); // 3 
    cout << "ms :" << ms.count() << endl;
    cout << "s  :" << s.count() << endl;
    //
    chrono::time_point<chrono::system_clock,days_types> today_2 = chrono::time_point_cast<days_types>(chrono::system_clock::now());
    cout << today_2.time_since_epoch().count() << " day since epoch" << endl;
    //
    cout << "................................." << endl;
    
    
    return 0;    

}