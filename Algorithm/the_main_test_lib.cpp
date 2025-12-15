//input output
#include<iostream> //#
#include<fstream>
#include<iomanip>
//#include<ios>
//#include<iosfwd>
//#include<istream>
//#include<ostream>
//#include<sstream>
//#include<streambuf>
//Thread support lib
//#include<mutex>
//#include<thread>
//#include<condition_variable>
//#include<future>
//Numerics lib
#include<complex>
#include<random>
#include<valarray>
#include<numeric>
//Language support
#include<exception>
#include<limits>
#include<new>
#include<typeinfo>
//localization
#include<locale>
#include<codecvt>
//General
#include<algorithm>
#include<chrono> //#
#include<functional>
#include<iterator>
#include<memory>
#include<stdexcept>
#include<tuple>
#include<utility>
//Containers
#include<array>
#include<bitset>
#include<deque>
#include<forward_list>
#include<list> //#
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<vector>
//WIN32
#include<Windows.h> //#
#include<direct.h>
//C lib
#include<cassert> // assert.h
#include<cctype> // ctype.h
//#include<cerrno> //errno.h // โดนเมน เรน ลำดับ error
//#include<cfenv> //fenv.h 
//#include<cfloat> //float.h
//#include<cinttypes> //inttypes.h
//#include<ciso646> // iso646.h
//#include<climits> //limits.h
//#include<clocale> // locale.h
#include<cmath> // math.h
//#include<csetjmp> //setjmp.h
//#include<csignal> //signal.h
//#include<cstdarg> // stdarg.h
//#include<cstdbool> //stdbool.h
//#include<cstddef> //stddef.h
//#include<cstdint> //stdint.h
//#include<cstdio> //stdio.h
//#include<cstdlib> // stdib.h
#include<cstring> //string.h
#include<ctgmath> //tgmath.h
#include<ctime> //time.h
//#include<cuchar> //uchar.h
//#include<cwchar> //wchar.h
//#include<cwctype> //wctype.h
#include<ratio> //ratio.h
#include<string>
// #include<bits/stdc++.h> // competitive
// ios::syc_with_stdio(false);
// cin.tie(0);
using namespace std;
class InputOutput{
    public: // iostream , std; cout cin cerr clog
       int Input(int i){ a = i; cout << a << endl; }
       int Input(string j){ name = j; cout << name << endl; }
       int Input(double q){ b = q; cout << b << endl; }
       void Print_H();

    private: 
        string name;
        int a;
        double b;
        
};
void InputOutput::Print_H(){
    cout << "Hello InputOutput" << endl;
}
class File_TXTQ{
    public:
        int Write_txt();
        int Read_txt();
        string text_edi;
};
int File_TXTQ::Write_txt(){
    ofstream MyFile("text.txt");
    MyFile << "Hello Developer K [A];" <<endl;
    MyFile.close();
}
int File_TXTQ::Read_txt(){
    ifstream ReadFile("text.txt");
    while(getline(ReadFile,text_edi)){
        cout << text_edi ;
    }
}
//**********************************************
//assert
print_assert(int* myInt){
    assert(myInt!=NULL);
    cout << *myInt << endl;
}
int array_test(){
    array<int,6> myarray ={4,8,12,16,18,32};
    // array<type,size> name ={value,...,n-size};
    cout << "my array containers" << endl;
    for(auto iw = myarray.begin();iw != myarray.end(); ++iw)
        cout << " " << *iw;
    cout << "\n";
    cout << "Reverse Array:";
    for(auto iw = myarray.rbegin();iw != myarray.rend(); ++iw)
        cout << " "<< *iw ;
    cout << "\n";
    cout << "Const Array Not Modify:cbegin,cend,crbegin,crend" << endl;;
    cout << "Size :" << myarray.size() << endl;
    cout << "Max_Size :" << myarray.max_size() << endl;
    cout << "Size of() :" << sizeof(myarray) << endl;
    cout << "Empty?? myarray ?? :" << (myarray.empty() ? "is empty" : "is not empty") << endl;
    cout << "operater [] :";
    array<int,10> arr_wa;
    for(int i=0 ; i<10; i++){ arr_wa[i] = i; }
    for(int i=0 ; i<10; i++){ cout << arr_wa[i]; }
    for(int i=0 ; i<10; i++) arr_wa.at(i) = i+1; cout << "\n";
    for(int i=0 ; i<10; i++) cout <<' ' << arr_wa.at(i);
    cout << "\n" << "Front arr_wa is:" << arr_wa.front() << endl;
    cout << "Back arr_wa is:" << arr_wa.back() << endl;
    cout << "Change Front and Back is 100" << endl;
    arr_wa.front() = 100;
    arr_wa.back() = 100;
    cout << "Front is:" << arr_wa.front() << ". Back is:" << arr_wa.back() << endl;
    cout << arr_wa.data() << endl;
    const char* cstr ="Test string";
    array<char,12> charray;
    memcpy(charray.data(),cstr,12); // <-- memcpy(array.data(),value,size); เอา ขนาด String มาอยุ่ใน array
    cout << charray.data() << endl;
    cout << "Fill in Array" << endl;
    array<int,5> Fill_Q;
    Fill_Q.fill(5);
    Fill_Q.fill(6); // <- เติมเต็ม
    for(auto iw = Fill_Q.begin();iw != Fill_Q.end();iw++) cout << " " << *iw;
    array<int,5> first_1 ={1,2,3,4,5};
    array<int,5> second_1 ={6,7,8,9,10};
    cout << "\n";
    cout << " First :";
    for(auto i=first_1.begin(); i != first_1.end(); i++) cout << " " << *i ;
    cout << " Second :";
    for(auto i=second_1.begin();i != second_1.end();i++) cout << ' ' << *i ;
    cout << "\n";
    first_1.swap(second_1);
    cout << "[Swap]" << endl;
    cout << "First :";
    for(auto i=first_1.begin();i != first_1.end(); i++) cout << " " << *i ;
    cout << "\n";
    cout << "Second :";
    for(auto i=second_1.begin(); i != second_1.end(); i++) cout << " " << *i ;
    cout << "\n";
    get<0>(first_1) = get<0>(second_1);
    cout << first_1[0] << ' ' << second_1[0] << ' ';
    cout << "\n";
    cout << "Test Vector";
    vector<int> fiveq(4,100);
    for(vector<int>::iterator i=fiveq.begin(); i != fiveq.end(); ++i) cout << " " << *i;
    cout << "\n";
    return 0;
}
int vector_TT(){
    vector<int> foo(5,0); // vector<type> food(size,??);
    cout << foo.size() << endl;
    foo = vector<int>(); // NULL;
    cout << foo.size() << endl;
    vector<int> myvector;
    for(int i=0;i<10;i++) myvector.push_back(i); // pop_back เอาออกมา
    cout << "\n";
    for(vector<int>::iterator i=myvector.begin();i!=myvector.end();++i) cout << " " << *i;
    cout << "\n"; // vector<int> ??(size,fill);
    //resize()
    cout << "capacity :" << myvector.capacity() << endl;
    cout << "max_size :" << myvector.max_size() << endl;
    //reserve(size); สำรอง ข้อมูล
    // การใช้ .shrink_to_fit() คือจะเปลี่ยนตามที่ล่าสุด
    // myvector(100); 100 myvector.resize(10); 100 myvector.shrink_to_fit(); 10
    // assign(size,fill<-value);
    //insert(position[??],value);(position,mount,value);
    //erase(begin,end); // clear(); <- ล้างใน vector ทั้งหมด
    //emplace(position,value) <= it seem a insert
    //emplace_back(value) จำการเอาค่ามาไว้หลังสุดเหมือน pop_back();
    // .get_allocator().allocate(value); <- value คือ การจอง ที่ว่าง มา 5 ที่
    // .get_allocator().construct(position,value) วางค่า
    // .get_allocator().destroy(position); <- ลบค่าออกไป
    // .get_allocator().deallocate(name,value) <- i d k ไม่รุ้อะ
    // สรุปได้ว่า สามารถใช้ เหมือน array ได้ แต่มีความหลากหลาย algorithm ให้ใช้
    return 0;
}
int deque_tt(){
    deque<int> mydeque;
    // เหมือน vector ทุกอย่าง เลย แต่เพิ่มมาคือ การ push_back , push_front,pop_back,pop_front,emplace,emplace_front,emplace_back

    return 0;
}
int forward_list_tt(){
    forward_list<int> ATapo;
    ATapo.insert_after(ATapo.before_begin(),11); // ก่อน 
    // เหมือน กับ deque เลย แต่จะเกิม back เป็น after
    //splice_after(position ที่จะใส่, ข้อมูล); (ตัวแปรที่จะใส่,ตัวแปรข้อมูล,ตั้งแต่ไหน,จนถึงไหน);
    //.remove_if(condition) มันจะ หาเงื่อนไขใน value เรื่อยๆว่า ถ้่าเป้นจริง จะลบ ถ้าไม่จริง จะไม่ลบ 
    /**
     * เช่น bool single(const int&value){ return(value <10); } แล้ว 
     *  .remove(single) <-- ถ้าค่าข้างในไม่่เกิน 10 จะลบ
     */
    // .unique(); ถ้า มี 1 1 1 หลายตัว มันจะทำให้ เหลือ 1 ตัวเดียวเป็นเอกลักษณ์
    //.merge(ตัวแปรที่เอามาใส่) จะจัดเรียงให้

}
int list_tt(){
    //เหมือน forward_list แปะ เลย 
    list<int> myList;
    return 0;
}
int stack_tt(){
    //เหมือน เลย แต่มี top เพิม่มา
    stack<int> mystack;
    return 0;
}
int queue(){
    //เหมือนกัน
}
int priority_queue_tt(){
    //เหมือนกัน
}
int set_tt(){
    // มีมาใหม่
    set<string> myset;
    myset.emplace_hint(myset.begin(),"Hi"); // <-- (ตั้งแต่, แปร);
    //.value_comp(); ไว้เปรียบเทียบ continaer เช่น set<int>::value_compare ??= ??.value_comp();
    //.key_comp(); ไว้เปรียบเทียบเหมือนกัน set<int>::key_compare ?? = ??.key_comp();
    // pair<set<int>::const_iterator,set<int>::const_iterator> ret;
    //ret = ??.equal_range(??); เท่ากับ ค่า ที่มี ??
    // ret.first ret.second
    // .lower_bound(เลื่อค่าแรก) , .upper(เลือกค่าสุด);
    //myset.erase(ตั้งแต่แรก,ถึงสุด)ว
    //count(value) นับ ไว้ใช้ เงื่อนไข
    // if(myset.count(i) !=0){}
    // .find(หาค่า);
}
int multiset_tt(){
    //เหมือนกัน
}
int map_tt(){
    //เหมือนกัน
}
int multimap_tt(){
    //เหมือนกัน
}
int unordered_set_tt(){
    // .bucket_count() จำนวนทั้งหมด
    // .max_bucket_count ความจุ สูงสุด
    // .bucket_size() ขนาด
    // .bucket(value) จะได้ค่าเป็น จำนวน
    // load_factor = size / bucket_count
    // max_load_factor(value / value); <-- max of load_factor
    // .rehash(value ex. rehash(12) #3  0-12
    // .reserve() เปลี่ยน ความจุ
    // unordered_set<string> stringset;
    // stringset myset;
    // stringset::hasher fn = myset.hash_function() <--ใช่ฟังชัน hash
    // unordered_set<string>myset;
    // bool ?? = ??.key_eq()("","")
}
int iomanip_q(){
    cout << hex << setiosflags(ios::showbase | ios::uppercase) << 100 << endl; // โชว์ เลขฐานสิบ แบบ ฐาน ตัวอักษรใหญ่
    cout << resetiosflags(ios::showbase) << 100 << endl; // ให้โชว์เลข ฐาน 
    cout << setbase(16) << 110 << endl; // 8 oct | 10 dec | 16 hex | อย่างอื่น จะใช้ resetiosflags(baseflied); // 110 ใน ฐาน 16
    cout << setbase(2) << setfill('x') << setw(10) << 77 << endl;
    cout << setprecision(5) << fixed; // fixed ทำให้เปลี่ยน มากกว่าค่าที่ ได้ อย่าง ถ้า เป็ฯ 3.174455 จะออกมาทั้งหมดเลย แต่ถ้า เติม fixed จะทำให้ออกค่ามาหมดเลย จะเป็น 0 
    cout << 3.14 << endl; // อย่างเช่น 3.1744550000;
    // get_money(value); put_money(value); รับค่า มาเช็ค
    //get_time(); put_time(); ใช้ร่วม กับ ctime เอาค่า มาคำนวณ
}

//Windows
const char g_szClassName[] = "My Windows :D";
LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wParam, LPARAM lParam){
    switch(msg){
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd,msg,wParam,lParam);
    }
    return 0;
}
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPevInstance,LPSTR lpCmdLine,int nCmdShow ){
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL,IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm = LoadIcon(NULL,IDI_APPLICATION);
    if(!RegisterClassEx(&wc)){
        MessageBox(NULL,"Windows Registratation Failed!","Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }
    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,g_szClassName,"Hello Windows!?",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,240,120,NULL,NULL,hInstance,NULL);
    if(hwnd == NULL){
        MessageBox(NULL,"Window Creation Failed!","Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }
    ShowWindow(hwnd,nCmdShow);
    UpdateWindow(hwnd);
    while(GetMessage(&Msg,NULL,0,0) > 0){
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}
void myfunction_q(int i){
    cout << ' ' << i ;
}
bool IsOdd(int i){ return ((i%2)==1);}
bool newfunction_wq(int m , int n){ return (m==n);}
bool comp_case_insensitive(char c1 , char c2){ return (tolower(c1)==tolower(c2)); }
int algorithm_tt(){
    array<int,5> ferm_wq = {3,5,7,11,13};
    if(all_of(ferm_wq.begin(),ferm_wq.end(),[](int i){return i%2;})) cout << " ALL elements are odd numbers."; 
    // all_of(first,last,condition or function); [](){} <-- ฟังชัน array (){} <-- จะเช็คทุกตัว ต้องเข้าเงื่อนไข ต้อง เป็น true ถึงจะทำงาน
    array<int,5> feq_w = {0,1,-1,3,-3};
    if(any_of(feq_w.begin(),feq_w.end(),[](int i){return i<0;})) cout << "There are negativ elements in range.\n";
    // any_of(first,last,condition) <-- ขอแต่มีตัวไรก็ตาม ที่เข้าเงื่อนไข ก็จะผ่าน 
    if(none_of(ferm_wq.begin(),ferm_wq.end(),[](int i){return i<0;})) cout << "There are no negative element in range.\n"; 
    // none_of เหมือนกันเลย แต่ เงื่อนไข ต้องเป็น false ถึงจะทำงาน ตรงข้าม กับ all_of
    vector<int> w21w ={10,20,30,40,50};
    for_each(w21w.begin(),w21w.end(),myfunction_q);
    cout << "\n";
    // for_each(first,end,function) มันจะ loop แล้ว เอาค่าแต่ละตัวไปทำงานต่อใน ฟังชัน
    int myints[] = {10,20,30,40};
    int * p;
    p = find(myints,myints+4,30); // (0,0+4, find 30); p = 30
    if(p != myints+4) cout << "Element found in myints:" << *p << endl;
    else cout << "Element not found in myints" << endl;
    vector<int> myvec (myints,myints+4); 
    vector<int>::iterator it;
    it = find(myvec.begin(),myvec.end(),30); // it = 30;
    if(it != myvec.end()) cout << "Element found in myvec :" << *it << endl;
    else cout << "Element not found in myvec." << endl;
    vector<int> w2l;
    w2l.push_back(15);
    w2l.push_back(20);
    w2l.push_back(50);
    vector<int>::iterator iqw = find_if(w2l.begin(),w2l.end(),IsOdd); // True
    cout << "The first odd value is :" << *iqw << endl;
    vector<int>::iterator q2e = find_if_not(w2l.begin(),w2l.end(),[](int i){return i%2;});
    cout << "The first even value is :" << *q2e  << endl;
    int mynums[] = {1,2,3,4,5,1,2,3,4,5}; // 
    vector<int> haystack (mynums,mynums+10);
    int needle1[] = {2,3}; // 
    vector<int>::iterator wqr = find_end(haystack.begin(),haystack.end(),needle1,needle1+2); // first1 last1 first 2 last2
    //auto wqr1 = find_end(haystack.begin(),haystack.end(),needle1,needle1+5); // first1 last1 first 2 last2
    // 1 , 5 , 1 , 3
    if(wqr !=haystack.end()) cout << "needle1 postion last:" <<(wqr-haystack.begin()) << endl;  // ไม่เท่ากับ ตัวสุดท้าย
    cout << distance(haystack.begin(),wqr) << endl; // ใช้ได้เหมือนกัน
    int patt2[] = {4,5,1};
    vector<int>::iterator ggqe = find_end(haystack.begin(),haystack.end(),patt2,patt2+3,newfunction_wq);
    if(ggqe != haystack.end()) cout << "Patt2 last found at position :" << (ggqe-haystack.begin()) << endl;
    //# ข้ออนุมาร โปรแกรม find_end(ลำดับแรก,สุดท้าย,แรก2, สุดท้าย2, function condition);
    // คือ การเอา Array อันที่ สอง ไปเปรียบเทียบ กับ Array อันที่ 1 ว่า pattern ของ Array 2 อยุ่ตรงไหน ของ ตัวแรก จะ Return เป็น ตำแหน่ง
    // อย่าง mynums มี10 ตัว pattern 1 2 3 4 5 1 2 3 4 5 เอา needle1 ไปเปรียบ มี 2 3 ซึ่ง มันอยุ่ ตัวที่ 6 จะ นับตัวที่เหมือนกัน และเป็นตำแหน่งล่าสุด
    // และ function ที่สุด จะเป็น patt2 4 5 1 มัน ต้องเป็น pattern แบบนี้ ซึ่งมันเจอ pattern แบบนี้อยุ่ตำแหน่งที่ 3 
    //สรุป เป็นการ หา pattern อีกตัวไหน มาเช็คตัวนึงว่า มีเหมือินกันไหม แล้ว จะแสดง ตำแหน่ง ของ pattern ที่เหมือนกัน ตัวล่าสุดออกมา
    //find_first_of เหมือน กับ find_end() เลย แต่ จะ return เป็น ค่ามันตรงๆเลย อย่าง เช่น "A" "a" "b"
    int mychars[] = {'a','b','c','A','B','C'};
    vector<char> hwqrw2 (mychars,mychars+6);
    vector<char>::iterator wvrq12;
    int cenq2[] ={'A','B','C'};
    wvrq12 = find_first_of(hwqrw2.begin(),hwqrw2.end(),cenq2,cenq2+3);
    if(wvrq12 != hwqrw2.end()) cout << "The first match is:" << *wvrq12 << endl;
    wvrq12 = find_first_of(hwqrw2.begin(),hwqrw2.end(),cenq2,cenq2+3,comp_case_insensitive);
    if(wvrq12 != hwqrw2.end()) cout << "The first match is:" << *wvrq12 << endl;
    // เช็ค อันที่ สอง จะมีเงื่อนไข หากเจอ ตัีวใหญ่แล้ว ให้เปลี่ยนเป็นตัวเล็ก
    int myints2[] = {5,20,5,30,30,20,10,10,20};
    vector<int> myvec2 (myints2,myints2+8);
    vector<int>::iterator it2;
    it2 = adjacent_find(myvec2.begin(),myvec2.end()); // หา ลำดับที่ ติดกับ อย่าง 30 
    if(it2 != myvec2.end()) cout << "The first pairs is:" << *it2 << endl;
    it2 = adjacent_find(++it2,myvec2.end(),newfunction_wq); // จะหาตัวต่อ ไป เต็ม ++it2 จะเป็น 10
    if(it2 != myvec2.end()) cout << "The Sencond pairs is:" << *it2 << endl;
    int mycount = count(myints2,myints+8,10); // ถ้าเจอ 10 จะนับ ตามจำนวนที่เจอ
    cout << "There are have 10 appers " << mycount << " times." << endl;
    vector<int> myvec3;
    for(int i =1;i<10;i++) myvec3.push_back(i); // 1 2 3 4 5 6 7 8 9
    int mycount2 = count_if(myvec3.begin(),myvec3.end(),IsOdd); // หาคี่
    cout << "My vec 3 :" << mycount2 << " odd values." << endl;
    vector<int> myqer1 = {10,20,30,40,50};
    int myqer2[] ={10,20,60,30,50};
    pair<vector<int>::iterator,int*> mypair;
    mypair = mismatch(myqer1.begin(),myqer1.end(),myqer2);
    cout << *mypair.first << " " << *mypair.second << endl;
    ++mypair.first,++mypair.second;
    cout << *mypair.first << " " << *mypair.second << endl;
    // ส่วน algorithm ตรงนี้ จะประมาณ ว่า จะหา ลำดับ 2 ตัว มาเปรียบกัน และจะเช็คว่า มันจะเอาตัวที่ แตกต่าง เมื่อเทียบกับใน พจน์เดียว กัน จะถูกเอาค่าออกมา
    // ถ้าจะดู ถัดไปให้ ++??.first,++?.second ด้วย
    if(equal(myqer1.begin(),myqer1.end(),myqer2)) cout << "All element is equal." << endl;
    else cout << "All element isn't equal." << endl;
    // equal จะเช็คว่า 2 ลำดับนั้น มีค่า เท่ากันไหม ต้องเหมือนกันทุกอย่าง ถึงจะเข้าเงื่อนไข จริง
    array<int,5> arr1 ={1,2,3,4,5};
    array<int,5> arr2 ={3,1,4,5,2};
    if(is_permutation(arr1.begin(),arr1.end(),arr2.begin())) cout << "2 array is same elements" << endl;
    // is_permtation (first1,last1,first2) จะเช็ค ทังหมดเลย ว่า มีเหมือนกันไหม 1-5 มีเหมือนกันไหม
    // เงื่อนไข คือ ต้องมีเลข เท่ากัน และ เหมือนกัน แต่แตกต่างกันที่ ตำแหน่ง ไม่ได้เรียง กัน
    //* search *// จะใช้เหมือน find_end และ find_first_of มัน return เป็นตำแหน่งให้ (first,last,first2,last2,function condition)
    //* seatch_n *// จะเป้ฯการหา elements เหมือน find เลย ว่าเจอตำแหน่งที่เท่าไหร่ 
    // เวลา cout << (it-myvector.begin())
    // เวลาตั้งค่า ?? = search_n(begin,end,count<- จะหาอย่างน้อยกี่ตำแหน่ง,หา value ,function condition);
    return 0;
}
int algorithm_2t(){
    int myints4[] = {10,20,30,40,50,60};
    vector<int> myvec4 (6);
    copy(myints4,myints4+6,myvec4.begin()); // <-- copy (fist,last,name)
    for(vector<int>::iterator i2=myvec4.begin();i2!=myvec4.end(); ++i2) 
        cout << " " << *i2;
    cout << "\n";
    int myints5[] = {1,2,3,4,5,6,7,8,9};
    vector<int> myvec5;
    myvec5.resize(9);
    cout << " my container :";
    copy_n(myints5,9,myvec5.begin());
    for(vector<int>::iterator i3=myvec5.begin(); i3 != myvec5.end(); ++i3)
        cout << " " << *i3;
    cout << "\n";
    // การใช้ auto it= copy_if(first,last,first2,condition function);
    //  distance(first.begin(),it);
    // copy_backward(first,last,result) <-- (begin,begin()+5,end()) <- 10 20 30 40 50
    // 10 20 30 10 20 30 40 50 ก็อบปี้ มาไว้ข้างหน้า
    //vector<int> ?? = move(contianer); ย้าย ตัวแปรไปอกีตัว
    //move_backward(first,last,result) ย้ายตำแหน่ง
    // swap(x,y) สลับกัน
    //swap_ranges(first,end,first2) จะสลับตั้งแต่ ตำแหน่งไหน
    //iter_swap(x,y) จะสลับ ตำแหน่ง x y array สลับ ที่กัน 10 20 : 99 99 สลับ 99 : 20 | 10 : 99
    // transform(first,last,first2 arg ,first arg2,function) เปลี่ยน ทั้งหมด ให้้ทำตามเงื่อนไข
    //replace(first,last,value old,value new);
    //replace_if(begin,end,function condition,value_new);
    //replace_copy(begin,end,first2,value_old,value new) <-- คือ การก็อบปี้ array อีกตัวไป อีกตัว และ เปลี่ยนค่ามัน
    // replace_copy_if(first,last,first2,function condition,value new); ถ้าเงือนไขถูก จะเปลี่ยนให้
    // fill(begin,end,value)
    // fill_n(begin,mount,value);
    // generate(being,end,function value) <-สร้าง ค่า ตาม function เช่่น rand()%100;
    // generate_n(begin,mount,function value)
    // remove(being,end,value)
    // remove_if(begin,end,function condition)
    // remove_copy(being,end,first2,value); สร้าง ตัวแปรใหม่มาเก็บและ ลบค่าตา
    // remove_copy_if(being,end,first2,function condition)
    // unique(being,end,| function condition)
    // unique(being,end,first2, | function condtition);
    // reverse(begin,end);
    // reverse_copy(begin,end,first2);
    // rotate(begin,end,postion) // 1 2 3 4 5 6 7 8 9 -> begin,begin+3,end -> 4 5 6 7 8 9 1 2 3
    //  rotate_copy(begin,end,position,first2);
    //  random_shuffle(begin,end, | function generate);
    // shuffle(begin,end, function generate <- random or function);
    // is_partitioned(begin , end , function condition) <- มันจะเอา ค่า ที่เป็น false ไปต่อหลัง
    // partition(begin,end, function condition) <- ถ้า ค่า เป็น true จะ ทำการ ลบ ค่าตัวนั้นออกจาก array
    //  stable_partition(begin,end,function) <- จะทำการแยกค่าเป็นสองตัวแปร
    // เช่น vector<int>::iterator it = stable_partition(begin,end,function condition) <- ค่าที่ตรงเงื่อนไขจะอยุ่ใน vector ส่วน ที่ไม่ตรงเงื่อนไข จะอยุ่ใน it
    // partition_copy(begin,end,first,last,function) มันจะแยก ไปสองส่วน ส่วนของ begin กับ first
    // value =partition_point(begin,end,function condition) <- ??.assign(begin,value) ทำการก็อบ เหมือนกัน
    // sort(begin,end, | function condition);
    // stable_sort(begin,end, function) <- ค่า ยังค่งที่อยุ่ ในบางตัว เมื่อเทียบ ค่าใกล้ๆกัน อย่าง 1 : Bob 2 : Bob <- สัมพันธ์กับ ลำดับ 0 - 9
    // bool compare_as_ints(double i , double j) return int(i) < int(j);
    // partial_sort(begin,end,first,function condition) เปรี่นย เทียบ ตัวืที่ begin กับ end
    //  partial_sort_copy(begin,end,first,last , function) เหมือนกัน แต่ ว่าเป็น การ copy ไปอีกตัวแปรหนึ่ง
    // prev_permutation(begin,end) จะ sort ตามครั้งที่เรียกละรอบ มันคือการ ค่อยๆ sort
    // is_sorted(begin,end) เช็ค เฉยๆ ว่า เรียงถูกต้องไหม จะเป็น true false
    // is_sorted_until(begin,end) <- คือ จะบอกเป็น element ว่า sort ไปที่ตำแหน่งไหน 
    // nth_element(begin,end,nth,function ) <- nth ? 
    // lower_bound(begin,end,value, function) ตัวแรก ตำแหน่ง
    // upper_bound(begin,end,value , function) ตัวสุดท้าย ตำแหน่ง
    // equal_range(begin,end,value , function) 
    // binary_search(begin,end,value, function) <- Check if
    // merge(begin,begin+5,second,second+5,first.begin )
    // inplace_merge(begin,begin+5,end);
    // includes(begin,end,first,last,function) if Check
    // set_union(begin,end,first,last,function) ร่วมกัน
    // set_intersection(begin,end,first,last,function) แยกกัน เอาตัวซ้ำ
    // set_difference(begin,end,first,last,function) เอา begin ไม่เอา first
    // set_symmetric_difference(begin,end,first,last,function)  ไม่เอาซ้ำ
    // Heap:
    // push_heap(begin,end)  ตำแหน่ง เอาหน้าออก
    // pop_heap(begin,end) เอาหลังออก
    // sort_heap(begin,end) เรียง
    // make_heap(begin,end) ค่ากลาง
    // is_heap(begin,end) if check
    //auto ?? = is_heap_until(begin,end) จำนวน
    ///////////////////////////////////////////////
    // min(begin,end)
    // max(begin,end)
    // auto ?? = minmax(??,??)
    // ??.first , ??.second ค่าต้ำสุด มากสุด
    // min_element(begin,end) หาค่าต่พสุด
    // max_element(begin,end) หาค่ามากสุด
    // auto ?? = minmax_element(begin,end,function)
    // ??.first, ??.second
    // lexicographical_compare(begin,end,function) เป็น begin < end = true
    // next_permutation(begin,end) ดู algorithm
    // prev_ermutation(begin,end)
    return 0;
}
int bitset_tt(){
    bitset<16> bit_w (10); // จะเป็นเลขฐาน
    cout << bit_w << endl;
    bitset<2> tes_q (10); // (int,ถ้าเป็น ตัวหนังสือ string("??"));
    cout << tes_q << endl; // .count() มีไว้นับเลข 1 <- ??.size - count = 0 times
    // .test(??) test ว่า ใน bit มี true หรืิอ false
    // .any() Check if มี bit ไหม เหมือน or
    // .none() Check if มี bit กี่ตัว เหมือน none ตรงข้าม หา 0
    // .all() Check เช็คทั้งหมดตรงเป็นจริง
    // .set(pos,value)
    // .reset(pos)
    // .flip(pos)
    // string ?? =  (?? <-bit <- bitset<?> ??) .to_string<char,string::traits_type,string::allocator_type>();
    // ??.to_ulong() จะเปลี่ยน bit เป็น ฐาน 2
    // ??.to_ullong() เปลี่ยน bit เป็น ฐาน 2 แต่ ขนาดจะใหญ่กว่า
    // การจะรู้ เรื่องนี้ ต้องศึกษาเรื่อง บิต
    return 0;
}
int chrono_ct(){
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
int codecvt_tt(){
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
struct ooops : exception { const char* what() const noexcept {return "Ooops \n";} };// สร้าง โครงสร้างใหม่ ชื่อ ooops ไป co-op กับ exception เพื่อเรียกใช้ what();
class text_exception : public exception{ 
        char* text_;
    public:
        text_exception(const char* text){ text_ = new char[strlen(text)+1]; strcpy(text_,text); }
        text_exception(const text_exception& e){ text_ = new char[strlen(e.text_)+1]; strcpy(text_,e.text_); }
        ~text_exception() throw(){ delete[] text_; }
        const char* what() const noexcept { return text_;}
};
class Base { virtual void member(){}};
class Derived : Base {};
void myunexpected(){ cerr << "unexpected handler called" << endl; throw; }
void myfunction_1() throw (int,bad_exception){ throw 'x';/* x is char not in exception-specification*/}
class polymorphic_wqr{virtual void Member(){}};
int exception_tt(){ 
    cout << endl; cout << "Case #1 :" << endl;
    ooops Event_t1;
    exception *p = &Event_t1;
    try{ throw Event_t1; }catch(exception& Messager_test1){ cout << Messager_test1.what() << endl; }
    try{ throw *p; }catch(exception& Messager_test1){ cout << Messager_test1.what() << endl; }
    try{ throw text_exception("HelloWorld"); } catch(exception &e){ cout << e.what() << endl; }
    try{ int* array_test_1 = new int[10000];} catch(bad_alloc &ba){ cerr << "bad_alloc caught: " << ba.what() << endl; } //bad_alloc ไว้จับ error เรื่อง memmory
    try{ Base b; Derived& rd = dynamic_cast<Derived&>(b);} catch(bad_cast& bc){ cerr << "bad_cast caught: " << bc.what() << endl; } // ไว้ดีกจับ lib : typeinfo ที่ชื่อว่า dynamic_cast แบบผิดๆ กับ Class
    set_unexpected (myunexpected);try{ myfunction_1(); }catch(int){ cerr << "caught int" << endl;}catch(bad_exception be){ cerr << "caught bad_exception" << endl; }catch(...){ cerr << "caught some othert exception" << endl; }
    function<int(int,int)> n1 = plus<int>();
    function<int(int,int)> n2;
    try{ cout << n1(10,20) << endl; cout << n2(10,20) << endl; }catch(bad_function_call){ cout << "ERROR: Bad Function call. " << endl; }
    try{ polymorphic_wqr* pb = 0; cout << typeid(*pb).name() << endl; }catch(bad_typeid& bt){ cerr << "bad_typeid caught:" << bt.what() << endl; }
     // ดักจับ error มี อีกเยอะ
    return 0;
}
struct IsOdder_2 : public unary_function<int,bool>{ bool operator()(int number){ return (number%2!=0); } };
struct Compare_2 : public binary_function<int,int,bool>{ bool operator()(int a,int b){ return (a==b); } };
struct IsOdd_3{ bool operator() (const int& x) const{ return (x%2==1); } typedef int argument_type; };
int functional_w1(){
    IsOdder_2 IsOdder_2_object;
    IsOdder_2::argument_type input;
    IsOdder_2::result_type result;
    cout << "\t\tStart Functional" << endl;    
    // cin >> input;
    input = 20;
    cout << "Please enter a number: " << input << endl; 
    result = IsOdder_2_object(input);
    cout << "Number " << input << " is " << (result?"odd":"even") << endl;
    Compare_2 compare_object;
    Compare_2::first_argument_type input1;
    Compare_2::second_argument_type input2;
    Compare_2::result_type result1;
    cout << "Please enter first number:";
    // cin >> input1; 
    input1 = 20;
    cout << endl;
    cout << "Please enter second number:";
    input2 = 20;
    // cin >> input2;
    cout << endl;
    result1 = compare_object(input1, input2);
    cout << "Numbers " << input1 << " and " << input2;
    if(result1){ cout << " are equal." << endl; }else{ cout << " are not equal." << endl; }
    int first[]={1,2,3,4,5};
    int second[]={10,20,30,40,50};
    int results[5];
    transform(first,first+5,second,results,plus<int>());// algorithm plus (begin,last,object plus,varible result, operator ??);
    for(auto i=0;i != 5;++i) cout << results[i] << " ";
    cout << endl;
    for(int i=0; i<5;i++) cout << results[i] << endl;
    int number[]={10,20,30};
    int results_1;
    results_1 = accumulate(number,number+3,100,minus<int>()); // algorithm accumulate สะสม ตั้งแต่ num[0] -> num[n]= Sn; 100 (minus<int>) Sn; -> 100 - Sn = result; 
    cout << "Result of Numbers : " << results_1 << ".\n";
    int numbers[9];
    int factorials[9];
    for(int i =0;i<9;i++) numbers[i] = i + 1;
        partial_sum(numbers,numbers+9,factorials,multiplies<int>()); // นำ ค่า เก่า มา ร่วม ด้วย
    for(int i = 0 ; i<9 ; i ++ ) cout << numbers[i] << "! is " << factorials[i] << endl;
    int first_1[]={10,40,90,40,10};
    int second_1[]={1,2,3,4,5};
    int results_11[5];
    transform(first_1,first_1+5,second_1,results_11,divides<int>()); // 10 20 30 10 2
    for(int i=0; i < 5; i++) cout << results_11[i] << " ";
    cout << endl;
    int numbers_2[]={1,2,3,4,5};
    int remainder[5];
    transform(numbers_2,numbers_2+5,remainder,bind2nd(modulus<int>(),2));
    for(int i =0;i<6;i++) cout << numbers_2[i] << " is " << (remainder[i]==0 ? "even" : "odd") << "\n";
    transform(numbers_2,numbers_2+5,numbers_2,negate<int>());
    for(int i = 0 ; i < 5; i++) cout << numbers_2[i] << " ";
    pair<int*,int*> pitter;
    int foo[]={10,20,30,40,50};
    int bar[]={10,20,40,80,160};
    pitter = mismatch(foo,foo+5,bar,equal_to<int>());
    cout << " First mismatching pair is : " << *pitter.first << " and " << *pitter.second << endl;
    int num_3[]={10,10,10,30,30};
    int* pt = adjacent_find(num_3,num_3+5,not_equal_to<int>());
    cout << " First Different is :" << *pt << endl;
    sort(numbers_2,numbers_2+5,less<int>()); // greater , greater_equal , less_equal<int>()
    for(int i = 0 ; i < 5 ; i ++ )  cout << numbers_2[i] << " " ;
    cout << "\n \t\t Logical " << endl;
    bool test_1[] = {true,false,true,false};
    bool nast_1[] = {true,true,false,false};
    bool result_bool[4];
    transform(test_1,test_1+4,nast_1,result_bool,logical_and<bool>()); // logical_or<bool>(); , logical_not<bool>();
    for(int i = 0 ; i < 4 ; i++ ) cout << test_1[i] << " And " << nast_1[i] << " = " << result_bool[i] << ". \n";
    int values[] = {1,2,3,4,5};
    int cx = count_if(values,values+5,not1(IsOdd_3())); // not1 -> unary not2 ->binary
    cout << " There are " << cx << " elements with even values. \n";
    int numbers_3[] = {10,20,30,40,50,10};
    int xc = count_if(numbers_3,numbers_3+6,bind1st(equal_to<int>(),10)); // bind2nd( operater , value)
    cout << " There are " << xc << " element that are equal to 10. \n";
    char* foo_3[] = {"10","20","30"};
    int bar_3[3];
    int sum_3;
    transform(foo_3,foo_3+3,bar_3,ptr_fun(atoi)); // <- แปลง char เป็น int ไปใส่ ใน bar
    sum_3 = accumulate(bar_3,bar_3+3,0);
    cout << "sum :" << sum_3 << endl;
    vector<string*>numbers_gg; // mem_ref vector<string>numbers;
    numbers_gg.push_back( new string ("one"));
    numbers_gg.push_back( new string ("two"));
    numbers_gg.push_back( new string ("three"));
    numbers_gg.push_back( new string ("four"));
    numbers_gg.push_back( new string ("five"));
    vector<int> length_gg(numbers_gg.size());
    transform(numbers_gg.begin(),numbers_gg.end(),length_gg.begin(),mem_fun(&string::length)); // <- namespace string
    // mem_ref It doesn't send to pointer or mem .
    for(int i = 0 ; i < 5 ; i++) cout << *numbers_gg[i] << " has " << length_gg[i] << " letters. \n" << endl;
    for(vector<string*>::iterator it = numbers_gg.begin(); it != numbers_gg.end(); ++it) delete *it;
    //] end 
    return 0;
}/*
struct myclass1{ myclass(int,int); myclass(initializer_list<int>);};
myclass foo {10,30}; // calls initalizer_list
myclass boo (10,30); // calls first construtor - > myclass(int,int); 
*/
template<class T> struct simple_container{
    T* data;
    unsigned n;
    simple_container(initializer_list<int> args){
        data = new T [args.size()];
        n = 0;
        for(T x : args){ data[n++]=x;}
    }
    T* begin(){ return (data);}
    T* end(){ return (data+n);}
};
int initializer_list_tt1(){
    simple_container<int> myobject {10,20,30};
    cout << " my object contains : ";
    for(int x : myobject) cout << " " << x ;
    cout << endl;
    return 0;
}
int iterator_fun_test1(){
    list<int> mylist;
    for(int i = 0 ; i < 10 ; i++) mylist.push_back(i*10);
    list<int>::iterator it = mylist.begin();
    advance(it,2);
    cout << "six element in mylist is :" << *it << endl;
    list<int>::iterator last = mylist.end();
    cout << "distance is : " << distance(it,last) << endl; // ระยะทาง ของ ตัวที่ 0 ถึง 9 = 8
    int foo[]={10,20,30,40,50};
    vector<int>bar;
    for(auto it=begin(foo); it != end(foo); ++it) bar.push_back(*it);
    cout << " bar containers : ";
    for(auto it= begin(bar); it != end(bar); ++it) cout << " " << *it;
    cout << endl;
    cout << "Ther last element is :" << *prev(bar.end()) << endl;
    for_each(bar.begin(),next(bar.begin(),3),[](int x){cout << " " << x;});
    cout << endl;
    //copy(begin,end,function(??)) -> copy(foo.begin(),foo.end(),back_inserter(foo)) -> 1 2 3 4 5 10 20 30 40 50 // front_inserter
    //function - > inserter(varible,position);
    //make_move_iterator(begin),make_move_iterator(end),value other,
    return 0;
}
int limits_t1(){
    cout << "max value of int :" << numeric_limits<int>::max() << endl;
    cout << "min value of int :" << numeric_limits<int>::min() << endl;
    cout << "int is signed :" << numeric_limits<int>::is_signed << endl;
    cout << "no sign bit in int  :" << numeric_limits<int>::digits << endl;
    cout << "int has infinity :" << numeric_limits<int>::has_infinity << endl;
    // boolalpha show true false , noboolalpha show 0 1
    return 0;
}
int locale_t1(){
    char c;
    int i = 0;
    char str[] = "Hello\'World My Program of me";
    while(str[i]){
        c=str[i];
        if(isspace(c)) c = '\n';
        cout << c; i++;
    } i =0; cout << endl;
    string test="First line \nSecond line\n";
    
    while(isprint(test[i])){
        cout << test[i] ; 
        i++;
    } i=0; cout << endl;
    while(!iscntrl(test[i])){ cout << test[i]; i++; } i = 0 ; cout << endl;
    while(test[i]){ if(isupper(test[i])){ test[i]=tolower(test[i]);} cout << test[i]; i++; } cout << endl; i++;
    // while(test[i]){ if(islower(test[i])){ test[i]=toupper(test[i]);} cout << test[i]; i++; } cout << endl; i++;
    //isalpha() หาตัวอักษร
    //isdigit เอาแค่ตัวเลขใน string
    //ispunct() เช็ค เครื่องหมาย
    //isxdigit เช็ค ฐาน สิบหก
    // isalnum เช็ค เลขทศนิยม ตัวใหญ่ตัวเล็ก อักษร
    // isgraph -> $%^
    // isblank() ช่องว่าง
    return 0;
}
int locale_t2(){
    locale loc;
    //cout.imbue(locale("ENGLISH_US"));
    // try{ loc = locale("en_US.UTF8");}
    // catch(runtime_error){loc = locale(loc,"",locale::ctype);}
    cout << "The selected locale is " << loc.name() << endl;
    // locale foo;
    // foo.global(locale(""));
    // locale bar("");
    // cout << (foo==bar?"same":"different");
    //# ศุึกษาเพิ่ม ซึ่ง เยอะ
    // locale เป็น lib ที่ใช้การแปล ใช้เกียวกับ text หรือ utf
    // ที่อยุ่ / local
    return 0;
}
struct C_2{ int * data;};
int memory_t1(){
    // auto_ptr<int> p1 (new int); // <- value , save type or disk space
    // *p1.get()=10; // 
    // auto_ptr<int> p2 (p1);
    // cout << *p2 << endl; // p1 <- null : auto_ptr
    // auto_ptr<int> p3(new int (10));
    // auto_ptr<int> result_plus (new int);
    // *result_plus = *p3 + *p2;
    // cout << *result_plus << " " << endl;
    // cout << "-----------------------" << endl;
    // typedef pair<int*,ptrdiff_t> mypair;
    // auto_ptr<mypair> p (new mypair);
    // *p = get_temporary_buffer<int>(5);
    // if(p->second >= 5){ for(int i = 0 ; i < 5 ; i++){p->first[i] = i*5;}
    // for(int i = 0 ; i<5 ; i++){ cout << p->first[i] << ' '; }
    // cout << endl;
    // }
    // return_temporary_buffer(p->first);
    // auto_ptr<int> p11;
    // *p11 = 10;
    // cout << *p11 << endl;
    // auto_ptr<int> auto_pointer (new int);
    // int * manual_pointer;
    // *auto_pointer = 10;
    // manual_pointer = auto_pointer.release();
    // cout << *manual_pointer << ' ' ;
    // auto_pointer.reset(new int);
    // *auto_pointer = 5;
    // cout << *auto_pointer ; 
    cout << " ==========================================" << endl;
    // shared_ptr<int> bun1; //0
    // shared_ptr<int> bun2 (nullptr); //0
    // shared_ptr<int> bun3 (new int); // 1
    // shared_ptr<int> bun4 (new int,default_delete<int>()); // 1
    // shared_ptr<int> bun5 (new int,[](int * p){ delete p;},allocator<int>()); // 2
    // shared_ptr<int> bun6 (bun5); // 2 // 0 -> move bun7
    // shared_ptr<int> bun7 (move(bun6)); // 2 
    // shared_ptr<int> bun8 (unique_ptr<int>(new int)); //1
    // shared_ptr<C_2> object_C_2 (new C_2); 
    // shared_ptr<int> bun9 (object_C_2,object_C_2->data); //2
    // cout << *bun1 << " " << *bun2 << " " << *bun3 << " " << *bun4 << ' ' << *bun5 << ' ' << *bun6 << ' ' << *bun7 << ' ' << *bun8 << ' ' << *bun9;
    // swap
    // ??.unique() -> true or false if value shared is false
    //
    return 0;
}
// struct Myclass_new{
    // int data[100];
    // MyClass_new(){ cout << "Constructed :" << this << endl; }
// };
int new_test1(){
    // cout << "1 :"; Myclass_new* nanda1 = new Myclass_new; //calls
    // cout << "2 :"; Myclass_new* nanda2 = new(nothrow)Myclass_new; // calls
    // cout << "3 :"; new (nanda2) Myclass_new; // calls
    // cout << "4 :"; Myclass_new* nanda3 = (Myclass_new*)::operator new (sizeof(Myclass_new)); //notcall
    // new[] -> array
    // delete
    // delete[] -> array
    return 0;
}
int numeric_1(){
    int a=1;
    int b[]={1,2,3,3};
    int c =accumulate(b,b+4,a,plus<int>());
    cout << c << "\n";
    //adjacent_difference(being,end,result , function condition) จะปริื้นความห่าง
    //สมมุติ เป็น คูณ มันจะเอาความ ห่าง มาคูณ หรือ มาคูณตัวด้านซ้าย
    //หรือ ถ้า + มันจะเอาตัวข้างหน้ามาบวกกัน
    //inner_product(a.being,a.end,b.begin,init,function,function); (a[i]*b[i]) ทุกตัวแล้วบวกกับไปบวก init
    // inner_product(a.begin,a.end,b.being,init,minus,divides) algorithm => (a[i] / b[i]) ทุกตัวแล้วบวกกัน sum - init;
    //partial_sum(begin,end,result,function) เก็บผลมาทำเรื่อยๆ เหมือน Sigma
    //iota(begin,end,value) ลำดับของ array work co กับ value

    return 0;
}
int random_t12(){
    srand(time(NULL));
    for(int i = 0 ; i < 5 ; i++) cout << rand() << ' ';
    cout << endl; 
    unsigned seed1 = chrono::system_clock::now().time_since_epoch().count();
    string str = "Hello";
    cout << "Please,enter a seed :" << str << endl;
    // getline(cin,str);
    seed_seq seed2 (str.begin(),str.end());
    minstd_rand0 g1 (seed1);
    cout << "A time seed produced:" << g1() <<endl;
    minstd_rand0 g2 (seed2);
    cout << "U seed produced:" << g2() << endl;
    cout << g1() << " " << g1.min() << " " << g1.max() << endl;
    int random_item = rand() % 10 +1;
    cout << "Random 1 to 10 :" << random_item << endl;
    // discard(val) -> ลบ
    // ex. random : 1170275710 -> 44925998
    return 0;
}
int ratio_testnan(){
    // เป็นเรื่องของ หน่วย
    // varible -> ratio<10,1> = 10**1 -> ratio<1,10> = 10**-1;
    //## และ typeinfo คือเช็คค่าเฉยๆ 
    return 0;
}
int utility(){
    //swap(a,b) -> temp = a , a==b , b== temp;
    // varible -> pair<int,int> val;
    // val (int,int); -> first , second
    // move() , forward<int>()
    //decltype(type) val -> decltype(declval<A>().value()) a;
    // move_if_noexcept(function condition)
    // valarray <int> val; เหมือน ฟังชันคณิต max min slice<- ค่าครึ่งหนึ่ง
    return 0;
}
int tuple_test1(){
    // tuple<int,char> ?? (10,"C");
    //swap()
    // get<type>(); -> get<0>(mytuple) = 20;
    // ?? = make_tuple(10,'a') -> int,char
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    InputOutput iot;
    iot.Input("Hello");
    iot.Print_H();
    File_TXTQ file;
    file.Write_txt();
    file.Read_txt();
    //******************
    //include<cassert>
    // assert();
    int a1 = 10;
    int * b =NULL;
    int * c =NULL;
    b=&a1;
    print_assert(b); 
        //print_assert(c); <-- erro ต้อง มีค่าไม่เท่ากับ NULL อารมเหมือนเช็คค่า
    /*****************/
    //include<cctype> เช็ค ประเภท string character
    //isalnum เช็ค มีตัวเลขไหม เช่น C3W
    //isalpha เช็ค ตัวอักษร เช่น C++
    //isblank เช็ค ค่าว่าง "\0" 
    //iscntrl เช็ค "\n"
    //isdigit เช็ค เลขฐานสิบ 1776ad is 1776
    //isgraph เช็ค กราฟิก ใน ไฟล์
    //islower เช็คตัวเล็ก
    //isupper เช็คตัวใหญ่
    //isprint เช็คพิมพ์
    //ispunct หาตัวอักษครเครื่องหมาย วรรคตอน ,
    //isspace หาตัวเว้นว่าง ' ' '\n' '\t'
    //isxdigit เช็ค ฐานสิบหก 
    //tolower เปลี่ยนตัวใหญ่เป็นตัวเล็ก
    //toupper เปลี่ยนตัวเล็กเป็นตัวใหญ่
    /***********************/
    array_test();
    vector_TT();
    deque_tt();
    iomanip_q();
    // atio() atof() atol() แปลง ข้อความเป็น เลข
   // WinMain(NULL,NULL,NULL,0);
    algorithm_tt();
    algorithm_2t();
    bitset_tt();
    chrono_ct();
    codecvt_tt();
    exception_tt();
    functional_w1();
    initializer_list_tt1();
    iterator_fun_test1();
    limits_t1();
    locale_t1();
    locale_t2();
    memory_t1();
    new_test1();
    numeric_1();
    random_t12();
    ratio_testnan();
    utility();
    MessageBox(NULL,"Complete","Testing in case",MB_OK );
    return 0;
}