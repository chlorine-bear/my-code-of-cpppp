#include <iostream>
using namespace std;
void fun1(void);
void fun2(void);
int main(){
    for (int i = 1; i <= 2; i++){
        fun1();
    }
    for (int j = 1; j <= 2; j++){
        fun2();
    }
    return 0;
}
void fun1(){
    cout << "Three blind mice\n";
}
void fun2(){
    cout << "See how they run\n";
}