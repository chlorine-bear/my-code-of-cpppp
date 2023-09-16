#include <iostream>
int main(){
    using namespace std;
    double lng;
    cout << "请输入以long为单位的距离：";
    cin >> lng;
    double ma = lng * 220;
    cout << "这个距离相当于" << ma << "码";
    return 0;
}