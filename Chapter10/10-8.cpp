#include <iostream>
using namespace std;

template <typename T>
class List
{
private:
    int len;
    int top;
    T * list;
public:
    List(int l)
    {
        len = l;
        top = 0;
        list = new T[len];
    }

    ~List()
    {
        delete [] list;
    }

    bool push(T val)
    {
        if (top < len)
        {
            list[top++] = val;
            return true;
        }
        return false;
    }

    T operator[](int ii)
    {
        return ii < top ? list[ii] : NULL;
    }

    bool revalue(int ii, T val)
    {
        if (ii < top)
        {
            list[ii] = val;
            return true;
        }
        return false;
    }

    bool isempty()
    {
        return top == 0;
    }

    bool isfull()
    {
        return top >= len;
    }

    void visit(void (* pf)(T &))
    {
        for (int i = 0; i < top; ++i)
            (* pf)(list[i]);
    }
};

void addOne(int & a)
{
    ++a;
}

/* void removeOne(int & a)
{
    --a;
} */

int main()
{
    List<int> myList(10);
    while (myList.push(5))
        continue;
    
    myList.revalue(5, 10);
    for (int i = 0; i < 10; ++i)
        cout << myList[i] << '\n';
    
    myList.visit(addOne);
    for (int i = 0; i < 10; ++i)
        cout << myList[i] << '\n';
    
    return 0;
}