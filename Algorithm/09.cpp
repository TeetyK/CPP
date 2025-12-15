#include<iostream>
#include<string.h>
#include<algorithm> // swap(a,b) <--- position a swap b
#include<utility>



using namespace std;
int main()
{
    
    int i= 0;
    int a[4]={};
    int list_num[4] ={};
    //int size_min =1000;
    for(i=0;i<3;i++){
        //cout << i ;
        cin >> list_num[i];        
    }
    
    //check list in a[]
    //for(int j=0;j<=2;++j){ // 12 3 15
//} 
    
        //for(int k=0;k<=2;++k){ // buble short
        /*
            if(a[0] < a[1]){ // 12 < 3 15
                list_num[0]=a[0];
                list_num[1]=a[1];
                if(a[1] <a[2]){
                    list_num[2]=a[2];
                }else{ // a[1] > a[2]
                    list_num[1] =a[2];
                    list_num[2]= a[1];
                }
            }else if(a[0] > a[1]){ // 12 > 3
                list_num[0] =a[1]; // 3
                list_num[1] =a[0]; // 12
                if(a[1] < a[2]){ // 12 < 15
                    list_num[2]=a[2];
                }
            }
            int list_answer[3] ={};*/
            /*
           for(int z =0;z<=2;z++){
               cout << list_num[z] << "\n" << endl;
           }*/
            // ค้างอยุที่ 14 2 15
                // 11  > 52
                //6 4 2
                // ต้องหาว่า ตอนไหนทำให้ A = 0
            int temp;
            for(int loop_now=0;loop_now<=2 ;loop_now++){
            if(list_num[0] > list_num[1]){ // 6 4 2 // loop 1
                temp = list_num[0]; // 6 > 4, temp = 6
                list_num[0] = list_num[1];// 6 =4,4 =6
                list_num[1] =temp; // 4 6 2
                 // 14 > 15 // false
                if(list_num[1] > list_num[2]){ // 6 > 2
                    temp = list_num[1]; // temp = 6,
                    list_num[1] = list_num[2]; // 6 = 2;
                    list_num[2] = temp; // 2 = 6;
                } // 4 2 6
            }
           
            if(list_num[1] > list_num[2]){ // 2 6 false
                    temp = list_num[1];
                    list_num[1] = list_num[2];
                    list_num[2] = temp;
                }
            if(list_num[0] > list_num[2]){ // 4 > 6 false
                temp  = list_num[0];
                list_num[0] =list_num[2];
                list_num[2] =temp;
                if(list_num[0] > list_num[1]){
                    int temp = list_num[0];
                    list_num[0] =list_num[1];
                    list_num[1] =temp;
                }
            }
            }
            /*for(int www = 0 ; www <= 2 ; www++){
                cout << list_num[www] << " " ;
            }*/
    /*for(int j =0;j<=2;++j){ // check 
        cout << list_num[j] << endl; // listnum[] ={3,12,15}
    }*/
   /* while(i <= 3){
        for(int j =i;list_num[j-1] >= list_num[j];j--){
            int temp =list_num[j-1];
            list_num[j-1] =list_num[j];
            list_num[j] =temp;
        }
        i++;
    }* /*
    vector<int> Vec;
    for(int q =1; q <= 3;q++){
        Vec[q] = list_num[q];
    } */
    /*
for(int w =0 ;w <= 2 ; w++){
    if(list_num[0] > list_num[1]){
        swap(list_num[0],list_num[1]);
        if(list_num[1] > list_num[2]){
            swap(list_num[1],list_num[2]);
        }
    }
    if(list_num[1] > list_num[2]){
        swap(list_num[1],list_num[2]);
    }
}*//*
    char ABC[3]={};
    cin >> ABC;
    for(int kuknow;kuknow < 3 ;kuknow++){
        switch(ABC[kuknow]){
            case 'A' : cout << list_num[0];
                break;
            case 'B' : cout << list_num[1];
                break;
            case 'C' : cout << list_num[2];
                break;
              
        }
    }*/



    
    int A,B,C;
    
    
    A = list_num[0];
    B = list_num[1];
    C = list_num[2];
    string ABC;
    //string ABC;
    cin >> ABC ;
    //getline(cin,ABC);
    if(ABC =="ABC"){
        cout << A << " " << B << " " << C << endl ;
    }else if(ABC =="ACB"){
        cout << A << " " << C << " " << B << endl ;
    }else if(ABC =="BAC"){
        cout << B << " " << A << " " << C << endl ;
    }else if(ABC =="BCA"){
        cout << B << " " << C << " " << A << endl ;
    }else if(ABC =="CAB"){
        cout << C << " " << A << " " << B << endl ;
    }else if(ABC =="CBA"){
        cout << C << " " << B << " " << A << endl ;
    }
    
   /* cout << A ;
    cout << B ;
    cout << C ;
    */



}
