#ifndef E3BF607B_452C_42F0_830A_DD375A0F0A7B
#define E3BF607B_452C_42F0_830A_DD375A0F0A7B
#include <iostream>

int MAX = 10;

template <typename T>
class Stack
{
private:
    T * pitems;
    int size;
    int top;

public:
    Stack(int n = MAX)
    {
        if (n > 0)
        {
            pitems = new T[n];
            size = n;
        }
        else
        {
            pitems = nullptr;
            size = 0;
        }
        top = 0;
    }

    Stack(const Stack & st)
    {
        delete [] pitems;
        pitems = new T[st.size];
        for (int i = 0; i < st.size; ++i)
            pitems[i] = st.pitems[i];
        size = st.size;
        top = st.top;
    }

    Stack & operator=(const Stack & st)
    {
        delete [] pitems;
        pitems = new T[st.size];
        for (int i = 0; i < st.size; ++i)
            pitems[i] = st.pitems[i];
        size = st.size;
        top = st.top;
        return *this;
    }

    ~Stack()
    {
        delete [] pitems;
        pitems = nullptr;
    }

    bool isEmpty() const {return top == 0;}
    bool isFull() const {return top == size;}

    bool push(const T & item)
    {
        if (top == size)
            return false;
        else
        {
            pitems[top++] = item;
            return true;
        }    
    }

    bool pop(T & item)
    {
        if (top == 0)
            return false;
        else
        {
            item = pitems[--top];
            return true;
        }
    }
};

#endif /* E3BF607B_452C_42F0_830A_DD375A0F0A7B */
