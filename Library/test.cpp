//header
#include<iostream>
#include<stdlib.h> // system()
#include<string.h> // string , memcpy , strcpy
#include<string>
#include<stdbool.h> // boolean
#include<ctype.h> // isalpha เช็คว่าเป็นตัวหนังสือไม่ ? 
#include<conio.h> // getch(); -> Anykey
#include<fstream> // file
#include<ctime>
using namespace std;

//function prototype
int create_user(); // สมัครสมาชิกใหม่
int main_menu(); // หน้าจอหลัก
void get_user(); // รับค่า มาเข้าใน struct user
int login();  // หน้าจอ login
int reset_string(); //รีเซ็ต ค่า ใน string                                                                              
int lib_main(); // หน้าจอหลัก 
int borrow_book(int num); //ยืมหนังสือ
int return_book(int num); //คืนหนังสือ
int show_login(); // หน้าจอแสดงรายละเอียดข้อมูล user login
int screen_continue(); // เช็ค ชื่อที่สมัครสมาชิก แล้วค่อยเข้ามาในตัวแปร user and login
//class 
class user{ // ข้อมูลผู้ใช้งาน
    public:
        int number;
        string name;
        int age;
        string class_age;
        int count_in_out;
        string role;
}user[30];
class check_user : public user{ // หน้าที่เช็คตอน register
    public:
        class user check;
        static int last_number; 
}check_user;
class login_user : public user{ // ที่การเป็นตัวแทน ใน user
    public:
        class user login;
}login_user;
class book{ // ข้อมูลหนังสือ
    public:
        string name;
        int number;
        string status;
        int amount;
        string name_booking;
        int num2;
        string name_book2;
        string name_booking2;
        string status2;
        int screen_book(int num,string name_book,string name_booking,string status_book); //หน้าจอแสดงหนังสือ
}book[20],show_book2;
class check_book : public book{
    public:
        class book check;
}check_book;
class File_main{
    public:
        int check_file(); // กรณี ไฟล์หาย
        void load_book(); //ประกาศค่าหนังสือ
        int update_book(); // โหลดข้อมูลใหม่ ใน book.txt
        int update_user(); // บันทึก ข้อมูลใหม่ใน user.txt
        int load_data();  // โหลดข้อมูลใน user.txt
}file_to;
class Time{
    public:
        time_t curr_time;
        tm * curr_tm;
        char date_str[100];
        char day_str[100];
        char month_str[100];
        char year_str[100];
        char hour_str[100];
        char minute_str[100];
        char second_str[100];
        string name;
        string book;
        string status;
        void timeline();
        void getTime();
        void writeTime();
        void getnumber(string name_user,string book_user,string status_user);
}today;
void Time::timeline(){
    ifstream readfile;
    readfile.open("TimeLine.txt",ios::in);
    string line;
    system("color 9");
    cout << " \t\t[  T I M E L I N E ] " << endl;
    while(getline(readfile,line)){
        cout << line << endl;
    }
    readfile.close();
}
void Time::getnumber(string name_user,string book_user,string status_user){
    name = name_user;
    book = book_user;
    status = status_user;
}
void Time::getTime(){
    time(&curr_time);
    curr_tm = localtime(&curr_time);
    strftime(date_str,50,"%A",curr_tm);
    strftime(day_str,50,"%d",curr_tm);
    strftime(month_str,50,"%B",curr_tm);
    strftime(year_str,50,"%Y",curr_tm);
    strftime(hour_str,50,"%H",curr_tm);
    strftime(minute_str,50,"%M",curr_tm);
    strftime(second_str,50,"%S",curr_tm);
}
void Time::writeTime(){
    ofstream time_file;
    time_file.open("TimeLine.txt",ios::app|ios::out);
    time_file << "[" << hour_str << ":" << minute_str << ":" << second_str << "] " << date_str << " " << day_str << " " << month_str << " " << year_str << " >> " << name << " : " << book << " [ " << status << " ]" << endl;
    time_file.close();
}
//#############################
int check_last_number_book = 0;
int count_repeat = 0;
// main function
int main(){ // ฟังก์ชัน หลัก
    int choice;
    file_to.check_file();
    while(choice != 0){
        choice = main_menu();
    }
    return 0;
}
int main_menu(){
    int choice_main;
    ifstream file;
    file.open("user.txt",ios::in);
    class user check;
    system("cls");
    file_to.load_data();
    file_to.load_book();
    system("color D");
    cout << "\n===========================================================================================================================";
   cout <<"\n  ___                ___       ___";
   cout <<"\n |   |              |___|     |   |                ___                  _______________       ___                 ____         ____";
  cout <<"\n |   |               ___      |   |               |   | _______        /               \\      |   | _______       \\   \\      /   /";
  cout <<"\n |   |              |   |     |   |               |   |/       \\      /                 \\     |   |/       \\       \\   \\    /   /";
  cout <<"\n |   |              |   |     |   |_________      |   /  __     \\    |   ______           |   |   /  __     \\       \\   \\__/   /";
  cout <<"\n |   |              |   |     |            \\      |     /  \\    |    |  |      |          |   |     /  \\    |        \\__    __/";
  cout <<"\n |   |              |   |     |    ______   \\     |    /    \\___|    |  |      |          |   |    /    \\___|           |  |";
  cout <<"\n |   |              |   |     |   |      |    |   |   |              |  |      |          |   |   |                     |  |";
  cout <<"\n |   |              |   |     |   |      |    |   |   |              |  |______|          |   |   |                     |  |";
  cout <<"\n |   |_________     |   |     |   |______|    |   |   |              |             |\\     |   |   |                     |  |";
  cout <<"\n |             |    |   |     \\              /    |   |               \\           /   |   |   |   |                     |  |";
  cout <<"\n |_____________|    |___|      \\____________/     |___|                \\_________/    |___|   |___|                     |__|";
  cout <<"\n==============================================================================================================================";

    while(file >> check.number >> check.name >> check.age >> check.role >> check.count_in_out >> check.class_age){
        if(file.tellg() < 1){ // check text in file
            // Notthing    
        }
        else if(check.number > 0){
            cout << "\n\t===========================";
            cout << "\n\t==   [4] Login           ==";
            break;
        }
    }
    file.close();
    cout << "\n\t==   [3] Time-Line       ==";
    cout << "\n\t==   [2] List-Book       ==";
    cout << "\n\t==   [1] Register        ==";
    cout << "\n\t==   [0] Exit            ==";
    cout << "\n\t===========================";
    cout << "\nInput Number : ";
    cin >> choice_main;
    if(choice_main == 1){
        create_user();
        return 2;
    }else if(choice_main ==0){
        return choice_main;
    }else if(choice_main ==4 && check.number >= 1){
        login();
        lib_main();
        return 2;
    }else if(choice_main ==2 && check.number >= 1){
        system("cls");
        system("color 3");
    cout << "\n=========================================+\n";
    cout << "\n             ___ ";             
    cout << "\n            |   |  ___   ___  | /";
    cout << "\n            |===| |   | |   | |/\\";
    cout << "\n            |___| |___| |___| |  \\";  
    cout << "\n+===========================================+\n";
        for(int j = 1 ; j < check_last_number_book ; j++){
            cout << "|[" << j << "] " << book[j].name <<"\t:" << book[j].status << "\n";
        }
        cout << "+======================================+\n";
        cout << "Press anykey to exit." << endl;
        getch();
        return 2;
    }else if(choice_main ==3 && check.number >= 1){
        system("cls");
        today.timeline();
        getch();
        return 2;
    }else{
        return 2;
    }
}
int create_user(){
    reset_string();
    system("cls");
    system("color A");
    cout << "\n===========================";
    cout << "\n==       Register        ==";
    cout << "\n===========================";
    cout << "\nName :";
    cin >> check_user.check.name;
    for(int i = 0 ; i < 30 ; i++){
        for(int j = 0 ; j < check_user.check.name.length() ; j++){
            if(!isalpha(check_user.check.name[j])){
                if(count_repeat > 0){
                    return 0;
                }
                count_repeat++;
                cout << "Name isn't string.\n";
                cout << "Press anykey to continue..\n";
                getch();
                create_user();
            }
        }
        if(check_user.check.name.compare(user[i].name) == 0){
            if(count_repeat > 0){
                return 0;
            }
            count_repeat++;
            cout << "Duplicate name, Please try again.\n";
            cout << "Press anykey to continue..\n";
            getch();
            create_user();
        }
    }
    cout <<"Age :";
    cin >> check_user.check.age;
    if(check_user.check.age <= 12){
        check_user.check.class_age = "Children";
    }else if(check_user.check.age <= 18){
        check_user.check.class_age = "Adolescent";
    }else{
        check_user.check.class_age = "Adult";
    }
    check_user.check.count_in_out = 0;
    check_user.check.role ="user";
    check_user.check.number = check_user.last_number + 1;
    screen_continue();
}   
int screen_continue(){
    int choice_user;
    system("cls");
    system("color E");
    cout << "\n\t+================";
    cout <<"\n\t   |\\  |";
    cout<<" \n\t   | \\ |";
    cout<<" \n\t   |  \\| umber : " << check_user.check.number;
    cout<<"\n\t    |\\  |";
    cout<<"\n\t    | \\ |";
    cout << "\n\t    |  \\|ame : " << check_user.check.name;
    cout<<"\n\t     __";
    cout<<"\n\t    /__\\";
    cout << "\n\t   /    \\ge : " << check_user.check.age;
    cout<<"\n\t     ___";
    cout<<"\n\t    | __"   ;
    cout << "\n\t    |___|roup-Age : " << check_user.check.class_age;
    cout<<"\n\t    |\\  |";
    cout<<"\n\t    | \\ |";
    cout << "\n\t    |  \\|umber of access times : " << check_user.check.count_in_out;
    cout<<"\n\t     __";
    cout<<"\n\t    |__|";
    cout << "\n\t    |  \\ole : " << check_user.check.role;
    cout << "\n\t====================";
    get_user();
    file_to.update_user();
    cout << "\nMain Menu [1]";
    cout << "\nBorrow book [0]";
    cout << "\nInput : ";
    cin >> choice_user;
    if(choice_user == 0){
        login_user.login.class_age = check_user.check.class_age;
        login_user.login.name = check_user.check.name;
        login_user.login.role = check_user.check.role;
        login_user.login.number = check_user.check.number;
        login_user.login.count_in_out = check_user.check.count_in_out;
        login_user.login.age = check_user.check.age;
        login_user.login.count_in_out++;
        lib_main();
    }
    else if(choice_user == 1){
        return 0;
    }else{
        cout << "Please input 0 or 1.	(¯ (00 ¯)) \n";
        cout << "Press anykey to re-again input";
        getch();
        screen_continue();
    }
}
void get_user(){ 
    user[check_user.check.number].number = check_user.check.number;
    user[check_user.check.number].name = check_user.check.name;
    user[check_user.check.number].age = check_user.check.age;
    user[check_user.check.number].class_age = check_user.check.class_age;
    user[check_user.check.number].count_in_out = check_user.check.count_in_out;
    user[check_user.check.number].role = check_user.check.role;
}
int File_main::load_data(){
    ifstream value_text;
    value_text.open("user.txt",ios::in);
    int i = 0;
    while(value_text >> check_user.check.number >> check_user.check.name >> check_user.check.age >> check_user.check.role >> check_user.check.count_in_out >> check_user.check.class_age){
        user[i].name = check_user.check.name;
        user[i].role = check_user.check.role;
        user[i].class_age = check_user.check.class_age;
        user[i].number = check_user.check.number;
        user[i].age = check_user.check.age;
        user[i].count_in_out = check_user.check.count_in_out;
        check_user.last_number = check_user.check.number;
        i++;
    }
    value_text.close();
}
int reset_string(){
    check_user.check.name.clear();
    check_user.check.role.clear();
    check_user.check.class_age.clear();
}
int File_main::update_user(){
    ofstream file_update;
    file_update.open("user.txt",ios::out);
    for(int i = 0 ; i <= check_user.check.number ; i++){
        file_update << user[i].number << " " << user[i].name << " " << user[i].age << " " << user[i].role << " " << user[i].count_in_out << " " << user[i].class_age << endl;
    }
    file_update.close();
}
int noUser = 0;
int login(){
    int isNum = 0;
    system("cls");
    system("color C");
    cout << "\t[Login]\n";
    cout <<"\n\t   |\\  |";
    cout<<" \n\t   | \\ |";
    cout << "\n\t   |  \\|ame : ";
    cin >> login_user.login.name;
    for(int q = 0 ; q < login_user.login.name.length() ; q++){
        if(!isalpha(login_user.login.name[q])){
            isNum++;
        }
    }
    if(isNum > 0){
        cout << "Please enter name only string not number\n";
        cout << "Press anykey to input name again";
        getch();
        login();
    }
    for(int j = 0 ; j < 30 ; j++){
        if(login_user.login.name.compare(user[j].name) == 0 && login_user.login.name.length() == user[j].name.length()){ 
            login_user.login.name = user[j].name;
            login_user.login.role = user[j].role;
            login_user.login.class_age = user[j].class_age;
            login_user.login.number = user[j].number;
            login_user.login.age = user[j].age;
            user[j].count_in_out++;
            login_user.login.count_in_out = user[j].count_in_out;
            cout << "Suscessful!\n";
            cout << "Enter anykey to continue\n";
            file_to.update_user();
            getch();
            break;
        }else if(j == 29){
            cout << "This user does not exist in the system\n";
            cout << "Press anykey to re-agin enter name.\n";
            getch();
            noUser++;
            break;
        }
    }
    if(noUser > 0){
        noUser = 0;
        login();
    }
}
void File_main::load_book(){
    ifstream book_file;
    book_file.open("book.txt",ios::in);
    int i = 1;
    check_last_number_book = 1;
    while(book_file >> check_book.check.number >> check_book.check.name >> check_book.check.amount >> check_book.check.name_booking ){
        book[i].number = check_book.check.number;
        book[i].name = check_book.check.name;
        book[i].amount = check_book.check.amount;
        book[i].name_booking = check_book.check.name_booking;
        if(book[i].amount == 1){
            book[i].status = "FREE";
        }else if(book[i].amount == 0){
            book[i].status = "BOOKED";
        }
        i++;
        check_last_number_book++;
        check_user::last_number++;;
    }
    book_file.close();
}
int show_login(){
    system("cls");
    system("color 3");
    cout << "\t[Information]\n";
    cout <<"\n+================+";
    cout << "\n|Number : " << login_user.login.number;
    cout << "\n|Name : " << login_user.login.name;
    cout << "\n|Age : "<< login_user.login.age;
    cout << "\n|Group-Age : " << login_user.login.class_age;
    cout << "\n|Number of access times : " << login_user.login.count_in_out;
    cout << "\n|Role : " << login_user.login.role;
    cout << "\n+================+";
}
int lib_main(){
    int choice_lib,number_book,select_first;
    bool running_login = false;
    while(running_login == false){
        show_login();
        system("color 9");
    cout << "\n=========================================+\n";
    cout << "\n             ___ ";             
    cout << "\n            |   |  ___   ___  | /";
    cout << "\n            |===| |   | |   | |/\\";
    cout << "\n            |___| |___| |___| |  \\";
    cout << "\n+=========================================+\n";
        for(int j = 1 ; j < check_last_number_book ; j++){
            cout << "|[" << j << "] " << book[j].name <<"\t:" << book[j].status << "\n";
        }
        cout << "+=====================================+\n";
        cout << "[1] Select book ";
        cout << "[0] : Exit\n";
        cout << "Select number to continue : ";
        cin >> select_first;
        if(select_first == 0){
            break;
        }else if(select_first == 1){
            cout << "+=================================+\n";
            cout << "Select number book : ";
            cin >> number_book;
            if(number_book > 0 && number_book < check_last_number_book){
                show_book2.screen_book(number_book,book[number_book].name,book[number_book].name_booking,book[number_book].status);
                cout << "[2] : Borrow Book\n";
                cout << "[1] : Return Book\n";
                cout << "[0] : Exit\n";
                cout << "Select your choice : ";
                cin >> choice_lib;
                if(choice_lib == 1){
                    return_book(number_book);
                }else if(choice_lib == 2){
                    borrow_book(number_book);
                }else if(choice_lib == 0){
                    continue;
                }else{
                    cout << "Please input 0,1,2 only\n";
                    cout << "Press anykey to re-again.\n";
                    getch();
                }
            }else{
                cout << "This book nothing" << endl;
                getch();
            }   
        }else{
            cout << "Please input 0 or 1 only\n";
            cout << "Press anykey to re-again.\n";
            getch();
        }
    }
}
int book::screen_book(int num,string name_book,string name_booking,string status_book){
    system("cls");
    int num2 = num;
    string name_book2 = name_book;
    string name_booking2 = name_booking;
    string status2 = status_book;
    system("color D");
    cout << "\n=========================================+\n";
    cout << "\n             ___ ";             
    cout << "\n            |   |  ___   ___  | /";
    cout << "\n            |===| |   | |   | |/\\";
    cout << "\n            |___| |___| |___| |  \\";
    cout << "\n+=======================================+\n";
    cout << "|[" << num2 << "] " << name_book2 << "\t :" << status2 <<"\n";
    cout << "| Borrowing user : " << name_booking2 << "\n";
    cout << "+=====================+\n";
}
int borrow_book(int num){ // การยืม
    if(book[num].amount == 0){
        cout << "Failed to borrow";
        getch();
    }else if(book[num].amount == 1 && book[num].name_booking.compare("--") == 0){
        cout << "Success to Borrow";
        getch();
        book[num].amount = 0;
        book[num].name_booking = login_user.login.name;
        book[num].status = "BOOKED";
        today.getTime();
        today.getnumber(login_user.login.name,book[num].name,book[num].status);
        today.writeTime();
        file_to.update_book();
    }
}
int return_book(int num){ // การคืน
    if(book[num].amount == 1){
        cout << "Failed to return";
        getch();
    }else if(book[num].amount == 0 && book[num].name_booking.compare(login_user.login.name) == 0){
        cout << "Success to Return";
        getch();
        book[num].amount = 1;
        book[num].name_booking = "--";
        book[num].status = "FREE";
        today.getTime();
        today.getnumber(login_user.login.name,book[num].name,book[num].status);
        today.writeTime();
        file_to.update_book();
    }
}
int File_main::update_book(){
    ofstream update_book;
    update_book.open("book.txt",ios::out);
    for(int i = 1 ; i < check_last_number_book ; i++){
        update_book << book[i].number << " " << book[i].name << " " << book[i].amount << " " << book[i].name_booking << endl;
    }
    update_book.close();
}
int File_main::check_file(){
    ifstream file_user;
    ifstream file_book;
    file_user.open("user.txt",ios::in);
    file_book.open("book.txt",ios::in);
    if(file_user.is_open() ==0){
        ofstream new_text;
        new_text.open("user.txt",ios::out);
        new_text << "0 test 20 test 0 Adult" << endl;
        new_text.close();
    }
    file_user.close();
    if(file_book.is_open() == 0){
        ofstream new_book;
        new_book.open("book.txt",ios::out);
        new_book << "1 Calculus_I 1 --" <<endl;
        new_book << "2 Math1 1 --" << endl;
        new_book << "3 Science 1 --" << endl;
        new_book << "4 Computer 1 --" << endl;
        new_book << "5 Japan_language 1 --" << endl;
        new_book << "6 Thai_language 1 --" << endl;
        new_book << "7 English_language 1 --" << endl;
        new_book << "8 Calculus_II 1 --" << endl;
        new_book << "9 Database_book 1 --" << endl;
        new_book << "10 Story_of_child 1 --" << endl;
        new_book << "11 C++_tutorial 1 --" << endl;
        new_book.close();
    }
    file_book.close();
}