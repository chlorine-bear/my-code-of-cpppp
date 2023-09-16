#include <iostream>
using namespace std;
const int SLEN = 30;
struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};
int getinfo(student pa[], int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);
void release(char * list, int n);
int main()
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
    {
        continue;
    }
    student * ptr_stu = new student [class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "Done.\n";
    return 0;
}
int getinfo(student pa[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << "Enter the fullname of Student "
             << i + 1 << ":\n";
        char ch = cin.get();
        if (ch == '\n')
        {
            break;
        }
        cin.getline((pa + i)->fullname, SLEN - 1);
        release((pa + i)->fullname, SLEN);
        ((pa + i)->fullname)[0] = ch;
        release((pa + i)->fullname + 1, SLEN - 1);
        cout << "Enter the hobby of Student "
             << i + 1 << ":\n";
        cin.getline((pa + i)->hobby, SLEN);
        cout << "Enter the ooplevel of Student "
             << i + 1 << ":\n";
        cin >> (pa + i)->ooplevel;
        cin.get();
    }
    return i;
}
void display1(student st)
{
    cout << "Fullname: " << st.fullname << endl;
    cout << "Hobby: " << st.hobby << endl;
    cout << "Ooplevel: " << st.ooplevel << endl;
}
void display2(const student * ps)
{
    cout << "Fullname: " << ps->fullname << endl;
    cout << "Hobby: " << ps->hobby << endl;
    cout << "Ooplevel: " << ps->ooplevel << endl;
}
void display3(const student pa[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Fullname: " << (pa + i)->fullname << endl;
        cout << "Hobby: " << (pa + i)->hobby << endl;
        cout << "Ooplevel: " << (pa + i)->ooplevel << endl;
    }
}
void release(char * list, int n)
{
    char temp;
    for (int i = 0; i < n / 2; i++)
    {
        temp = * (list + i);
        * (list + i) = * (list + n - i - 1);
        * (list + n - i - 1) = temp;
    }
}