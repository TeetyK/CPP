/**
 * @file test_.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
    vector,stack,map,priority_queue,set,queue
    utility,string,new,memory,list,locale,limits,algorithm,array
    cstdilb
*/
#include<iostream>
#include<new>
#include<array>

int pointer(int roundtrack){
    //int roundtrack;
    int i,j;
    int *p;
    p = new (std::nothrow) int[roundtrack];
    for(i=1;i<=roundtrack;i++){
        std::cin>> p[i];

    }
    for (j=1;j<=roundtrack; j++)
    {
        std::cout<< p[j] <<","<<std::endl;
        delete[] p;
    }
    delete p;
    return 0;
}
int main(){
    std::cout <<"HelloWorld"<< std::endl;
    //int a;
    //std::cin>> a ;
    //std::cout << a << std::endl;
    
    //int *b = &a;
    //std::cout << b << std::endl;
    //std::cout << *b << std::endl;
    //int c;
    //std::cin >> c ;
    //pointer(c);
    


    return 0;
}