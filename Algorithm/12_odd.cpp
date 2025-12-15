#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
    // pattarn
    string stair_1   = "..#..";
    string stair_2   = ".#.#.";
    string stair_1m3 = "..*..";
    string stair_2m3 = ".*.*.";
    //#######################
    string text_in ={};
    cin >> text_in ;
    int size_set = text_in.size();
    string list_text[size_set]={};
    int c=0;
    for(char i:text_in){
        
        list_text[c]= i;
            if( (c+1)%3 == 0 ){
                cout << stair_1m3 ;
                //cout << c ;
            }else{
                cout << stair_1 ;
                //cout << c ;
            }

        //cout << list_text[c] << endl;
        c++;

    }
    c=0;
    cout << "\n";
    for(char i:text_in){
        
        list_text[c]= i;
            if( (c+1)%3 == 0 ){
                cout << stair_2m3 ;
                //cout << c ;
            }else{
                cout << stair_2 ;
                //cout << c ;
            }

        //cout << list_text[c] << endl;
        c++;

    }
    c=0;
    cout << "\n";
        for(char i:text_in){
        
        list_text[c]= i;
            if( (c+1)%3 == 0 ){
                cout << "#" << "." << i << "." << "#" ;
                //cout << c ;
            }else{
                cout << "#" << "." << i << "." << "#" ;
                //cout << c ;
            }

        //cout << list_text[c] << endl;
        c++;

    }
    c=0;
    cout <<"\n";
        for(char i:text_in){
        
        list_text[c]= i;
            if( (c+1)%3 == 0 ){
                cout << stair_2m3 ;
                //cout << c ;
            }else{
                cout << stair_2 ;
                //cout << c ;
            }

        //cout << list_text[c] << endl;
        c++;

    }
    c=0;
    cout << "\n" ;
        for(char i:text_in){
        
        list_text[c]= i;
            if( (c+1)%3 == 0 ){
                cout << stair_1m3 ;
                //cout << c ;
            }else{
                cout << stair_1 ;
                //cout << c ;
            }

        //cout << list_text[c] << endl;
        c++;

    }
  
    


    //cout << text_in.size() << endl;
    /*
    for(int i=0;i<size_set ;i++){
        if(i % 3 == 0){
            cout << stair_1m3 << endl;
        }else{
            cout << stair_1 << endl;
        }
    }*/
    //  cout << "\n" << stair_1 << "\n" << stair_2 << "\n" << ".#" << text_in << "#." << "\n" << stair_2 << "\n" << stair_1 ;
    return 0;
}