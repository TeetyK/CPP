#include<iostream>
#include<cmath>

using namespace std;

int main(){
    string name;
    cin >> name ;
    int size_name = name.size();
    string list_n[size_name]={};
    int c=0;
    for(char i:name){ // get value
      // cout << i << endl;
        list_n[c]=i;
        c++;

    } 
    //Check Value in list what in?
    //cout << list_n[0] << endl;
    //cout << list_n[1];
    //cout << list_n[2] << endl;
    /*
    ..#..
    .#.#.
    #.?.#
    .#.#.
    ..#..
    
    ..#.. .#. ..*..
    .#.#. #.# .*.*.
    #.?.# .?. *.?.*
    .#.#. #.# .*.*.
    ..#.. .#. ..*..

    
    ..#.. .#. ..*.. .#..
    .#.#. #.# .*.*. #.#.
    #.?.# .?. *.?.* .?.#
    .#.#. #.# .*.*. #.#.
    ..#.. .#. ..*.. .#..
    */
   //sort pattarn
    for(int i=0;i<5;i++){ // colum 0-4

        for(int j =0;j<size_name;j++){ // row 0 - 3 is: ASD
            //Face
                if(i==0 or i==4){
                    for(int k =0; k < 2; k++){
                        cout << "." ;
                    }
                }else if(i==1 or i==3){
                    for(int u=0;u<2;u++){
                        for(int x =0; x < 2 ; x++){
                            if(x==0){
                                cout << "." ;
                            }else if(x ==1){
                                if((j+1)%3 ==0){
                                    cout << "*";
                                }else{
                                cout << "#" ;
                                }
                            }
                        }
                    }
                }
                else if(i ==2){
                    if(j < 1){
                    for(int z =0; z<2;z++){
                        if(z==0){
                        cout<< "#";
                        }else if(z==1){
                            cout << ".";
                            
                        } 
                        
                    } 
                    cout << list_n[j];
                    //cout << j ;
                    
                    if((size_name -1) ==0){
                        cout <<"";
                    }else{
                    for(int d=0;d<2;d++){
                  
                        if(d==0){
                            cout << ".";
                        }else if(d==1){    
                            cout << "#";
                        }
                        if((d+1) ==2){
                            cout << ".";
                        }
                    
                        }
                    }   
                        
                    
                    }
              
                   if(1 <= j && (j+1)!=size_name){
                       
                       
                       for(int e=0;e<2;e++){
                           if(e==0){
                               cout << list_n[j];
                           }else if(e==1){
                               for(int r=0;r<2;r++){
                                   if(r==0){
                                       cout << ".";
                                   }else if(r==1){
                                       if((j+2)%3==0 || (j+1)%3 ==0){
                                           cout << "*";
                                       }else{
                                       cout << "#";
                                       }
                                   }if((r+1)==2){
                                       cout << ".";
                                   }
                               }
                           }
                           
                       }
                       
                   }
                    
                   if((j+1)==size_name){
                       if(j ==0){
                         cout << "";  
                       }else if( j>0){
                       cout << list_n[j];
                       }
                       for(int as=0;as<2;as++){
                           if(as==0){
                               cout << ".";
                           }else if(as==1){
                               if((j+1)%3==0){
                                   cout << "*";
                               }else{
                               cout << "#";
                               }
                           }
                       }
                   }
                    
                    
                }
                


                // pattern back
                if(i==0 or i==4){ // row 0 | row 4
                    if(0 < j){
                        cout << ".";
                        if((j+1)%3 ==0){
                            cout << "*";
                        }else{
                            cout << "#";
                        }
                    }
                    else{
                        cout << "#" ;
                    }
                }else if(i==1 or i==3){
                    cout << "";
                  
                  
                }




            //Check Last 
            if((j+1) == size_name){
                if(i==0 || i==4){
               for(int a=0;a<2;a++){
                   cout << "." ;
               }
                }else if(i==1 || i==3){
                    cout << ".";
                }
            }

        }
        cout << "\n" ;
    }

    
    
    
    
    
    
    return 0;
}
