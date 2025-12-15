#include<iostream>
#include<csignal>

using namespace std;
void signalHandle(int signum){ cout << signum << endl; exit(signum); }
/** การแจ้งเตื่อน
 * SIGABRT  การยุติ เรียก abort
 * SIGFPE
 * SIGILL
 * SIGINT
 * SIGSEGV
 * SIGTERM
 * 
 */
int main(){
    signal(SIGINT,signalHandle);
    while(1){
        cout << "Going to sleep" << endl;
        raise(SIGINT); // จะขึ่นแจ้งเตื่อน 
    }
    return 0;
}