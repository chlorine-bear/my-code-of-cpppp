#include <iostream>
#define deg_min 60
#define min_sec 60
int main(){
    using namespace std;
    cout << "Enter a latitude in degrees, minutes, and seconds:\n";
    double degree, minute, second;
    cout << "First, enter the degrees: ";
    cin >> degree;
    cout << "Next, enter the minutes of arc: ";
    cin >> minute;
    cout << "Finally, enter the seconds of arc: ";
    cin >> second;
    double ans = degree + (minute + second / min_sec) / deg_min;
    cout << degree << " degrees, "
        << minute << " minutes, "
        << second << " seconds = "
        << ans << " degrees.";
    return 0;
}