#include<iostream>

using namespace std;
int find_prime(int i);
int main(){
    find_prime(11);
}
int find_prime(int i){
    int *array = new int[i];

    int count = 0;
    for(int j=1;j<i;++j){
        int q=2;
        for(;q<=j-1;q++)
        {
            if(j%q == 0)
                break;
        }

        if(q==j && q != 2){
            array[count] = j; 
            // cout<<j<<endl;
            count++;
        }
    }
    int max = -100;
    for(int i = 0 ; i < count ; i++){
        if(array[i] > max){
            max = array[i];
        }

    }
    return max;
}