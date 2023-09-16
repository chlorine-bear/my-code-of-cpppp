#include <iostream>
#include <cstring>
using namespace std;

struct customer
{
    char fullname[35];
    double payment;
};

class stack
{
private:
    enum {MAX = 10};
    customer items[MAX];
    int top;
public:
    stack(): top(0) {};
    ~stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const customer & item);
    bool pop(customer & item);
};

stack::~stack() {}

bool stack::isempty() const
{
    return top == 0;
}

bool stack::isfull() const
{
    return top >= MAX;
}

bool stack::push(const customer & item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    return false;
}

bool stack::pop(customer & item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    return false;
}

int main()
{
    const char str[35] = "My String\0";
    customer cust;
    strcpy(cust.fullname, str);
    cust.payment = 100;
    stack custs;

    while (custs.push(cust))
        continue;
    
    customer temp;
    double sum = 0;
    while (custs.pop(temp))
        sum += temp.payment;
    
    cout << sum << '\n';
    return 0;
}