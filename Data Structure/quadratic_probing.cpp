#include<iostream>
#include<conio.h>
using namespace std;
int insert(int i);
int delection(int i);
int display(int i);
int search(int i);
int size_table = 15;
int choice = -1;
int *array =new int[size_table];
int *check = new int[size_table];
int check_hashing(int i,int j);
int delete_hashing(int i , int j);
int search_hashing(int i , int j);
int main(){
    for(int i = 0 ; i < size_table ;i++){
        array[i] = -1;
        check[i] = 0;
    }
    system("cls");
    while(choice != 0){
        cout << "\t\tQuadratic Probing (Array)" << endl;
        cout << "\t1 : Insert" << endl;
        cout << "\t2 : Deletion" << endl;
        cout << "\t3 : Search" << endl;
        cout << "\t4 : Display" << endl;
        cout << "\t5 : Input number table (standard = " << size_table << " )" << endl;
        cout << "\t0 : Exit" <<endl;
        cout << "Enter your choice : " ;
        cin >> choice;
        if(choice == 1){
            insert(size_table);
        }else if(choice == 2){ 
            delection(size_table);
        }else if(choice == 3){
            search(size_table);
        }else if(choice == 0){
            break;
        }else if(choice == 4){
            display(size_table);
        }else if(choice == 5){
            int table = 0;
            cout << "Enter table :";
            cin >> table;
            size_table = table;
        }else{
            cout << "Unknown choice" << endl;
        }
        system("cls");
    }
    return 0;
}
int display(int i){
    int round = i;
    cout << endl;
    cout << "\t|-----[Table]-----|" << endl;
    for(int loop = 0 ; loop < round ; loop++){
        cout << "\t\t+======+" << endl;
        cout <<"\t"<< loop << "\t|  "  ;
        if(array[loop] == -1){
            cout << "  ";
        }else if(array[loop] >= 10){
            cout << array[loop];
        }else{
            cout << " "<< array[loop];
        }
        cout << "   |" << endl;
        cout << "\t\t+======+" << endl;
    }
    getch();
}
int insert(int i){
    int number;
    cout << "Insert number :" ;
    cin >> number;
    if(check_hashing(i,number) == 0){
        display(i);
        cout << "Sussesfully inserted (hash)" << endl;
        getch();
    }else{
        int q = 1;
        int count = 1;
        int hash1 = (number % i);
        while(count != size_table){
            if(array[(hash1 + (q * q)) % i] == -1 && check[(hash1 + (q * q)) % i] == 0){
                array[(hash1 + (q * q)) % i] = number;
                check[(hash1 + (q * q)) % i] = 1;
                display(i);
                cout << "Sussesfully inserted (collision)" << endl;
                getch();
                break;
            }
            q++;
            count++;
        }
        if(count == size_table){
            cout << "Faiiled inserted (collision)" << endl;
            getch();
        }
    }
}
int check_hashing(int i,int j){
    int hash1 = (j % i);
    if(array[hash1]== -1 && check[hash1] == 0){
        array[hash1] = j;
        check[hash1] = 1;
        return 0;
    }else{
        return 1;
    }
}
int delection(int i){
    int number;
    cout << "Delete number :";
    cin >> number;
    if(delete_hashing(i,number) == 0){
        display(i);
        cout << "Sussesfully delected (hash)" << endl;
        getch();
    }else{
        int q = 1;
        int count = 1;
        int hash1 = (number % i);
        while(count != size_table){
            if(array[(hash1 + (q * q)) % i] != -1 && check[(hash1 + (q * q)) % i] == 1){
                array[(hash1 + (q * q)) % i] = -1;
                check[(hash1 + (q * q)) % i] = 0;
                display(i);
                cout << "Sussesfully deleted (collision)" << endl;
                getch();
                break;
            }
            q++;
            count++;
        }
        if(count == size_table){
            cout << "Faiiled inserted (collision)" << endl;
            getch();
        }
    }
}
int search(int i){
    int number;
    cout << "Search number :";
    cin >> number;
    if(search_hashing(i,number) == 0){
        cout << "Found number (hash)" << endl;
        getch();
    }else{
        int q = 1;
        int count = 1;
        int hash1 = (number % i);
        while(count != size_table){
            if(array[(hash1 + (q * q)) % i] == number && check[(hash1 + (q * q)) % i] == 1){
                cout << "Found number (collision)" << endl;
                getch();
                break;
            }
            q++;
            count++;
        }
        if(count == size_table){
            cout << "Not Found number (collision)" << endl;
            getch();

        }
        return 0;
    }
}
int delete_hashing(int i , int j){
    int hash1 = (j % i);
    if(array[hash1]!= -1 && check[hash1] == 1){
        array[hash1] = -1;
        check[hash1] = 0;
        return 0;
    }else{
        return 1;
    }
}
int search_hashing(int i , int j){
    int hash1 = (j % i);
    if(array[hash1] == j && check[hash1] == 1){
        return 0;
    }else{
        return 1;
    }
}