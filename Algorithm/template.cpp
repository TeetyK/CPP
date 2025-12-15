#include<iostream>
using namespace std;
    
template <typename T> // การสร้าง function template
T const& Max(T const& a,T const& b){
    return a < b ? b : a;
}
template <class A>
class Test{
    public:
        A get_info(){  }

    private:

}/*
 * template<class ??>function;
 * template<typename ??>function;
 * 
 */
int main(){
    int i = 39;
    int j = 20;
    cout << Max(i,j) << endl;




}