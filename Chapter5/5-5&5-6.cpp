#include <iostream>
#include <string>
using namespace std;
int main(){
    /* Using char* array */
    cout << "Using char* array.\n";
    /* Using string array */
    cout << "Using string array.\n";
    string month[12] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    int num[12];
    int total = 0;
    for (int i = 0; i < 12; ++i){
        cout << month[i] << ": ";
        cin >> num[i];
        total += num[i];
    }
    cout << "Total: " << total << endl;
    /* Using 2-D char* array */
    cout << "Using 2-D char* array.\n";
    /* Using 2-D string array */
    cout << "Using 2-D string array.\n";
    int nums[3][12];
    total = 0;
    int totals[3];
    for (int i = 0; i < 3; ++i){
        totals[i] = 0;
        for (int j = 0; j < 12; ++j){
            cout << "Year " << i + 1 << ", "
                 << month[j] << ": ";
            cin >> nums[i][j];
            totals[i] += nums[i][j];
            total += nums[i][j];
        }
    }
    for (int i = 0; i < 3; ++i)
        cout << "Year " << i + 1 << ": "
             << totals[i] << endl;
    cout << "Total: " << total << endl;
    return 0;
}