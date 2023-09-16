#include <iostream>
#include <string>
#include <cstring>
int main(){
    using namespace std;
    char first_name[20], last_name[20], name[50];
    cout << "Enter your first name: ";
    cin.getline(first_name, 20);
    cout << "Enter your last name: ";
    cin.getline(last_name, 20);
    strcpy(name, first_name);
    strcat(name, " , ");
    strcat(name, last_name);
    cout << "Here's the information in a single string: " << name
        << "\n--Produced by cstring.\n";
    string First_name, Last_name;
    cout << "Enter your first name: ";
    getline(cin, First_name);
    cout << "Enter your last name: ";
    getline(cin, Last_name);
    string Name = First_name + " , " + Last_name;
    cout << "Here's the information in a single string: " << Name
        << "\n--Produced by string.\n";
}