#include <iostream>
#define day_hr 24
#define hr_min 60
#define min_sec 60
int main(){
    using namespace std;
    cout << "Enter the number of seconds: ";
    long secs;
    long day, hour, minute, second;
    cin >> secs;
    minute = secs / min_sec;
    second = secs % min_sec;
    hour = minute / hr_min;
    minute = minute % hr_min;
    day = hour / day_hr;
    hour = hour % day_hr;
    cout << secs << " seconds = "
        << day << " days, "
        << hour << " hours, "
        << minute << " minutes, "
        << second << " seconds";
    return 0;
}