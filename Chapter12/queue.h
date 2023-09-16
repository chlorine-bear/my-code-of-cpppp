#ifndef D4F134DD_CC03_4205_AB54_734D967E5BB0
#define D4F134DD_CC03_4205_AB54_734D967E5BB0
#include <iostream>
#include <cstdlib>

class Customer
{
private:
    long arrive;        // arrival time for customer
    int processtime;    // processing time for customer

public:
    Customer(): arrive(0), processtime(0) {}
    void set(long when)
    {
        arrive = when;
        processtime = std::rand() % 3 + 1;
    }
    long when() const {return arrive;}
    int ptime() const {return processtime;}
    ~Customer() {}
};

struct Node
{
    Customer item;
    Node * next;
};

class Queue
{
private:
    struct Node
    {
        Customer item;  // data stored in the node
        Node * next;    // pointer to next node
    };
    enum {Q_SIZE = 10};
    Node * front;       // pointer to front of Queue
    Node * rear;        // pointer to rear of Queue
    int items;          // current number of items in Queue
    const int qsize;    // maximum number of items in Queue

public:
    Queue(): qsize(0), items(0) {front = rear = nullptr;}
    Queue(int qs = Q_SIZE): qsize(qs), items(0) {front = rear = nullptr;}
    ~Queue()
    {
        Node * temp;
        while (front)
        {
            temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty() const {return items == 0;}
    bool isFull() const {return items == qsize;}

    int queuecount() const {return items;}

    bool enqueue(const Customer & item)
    {
        if (isFull())
            return false;
        Node * add = new Node;
        add->item = item;
        add->next = nullptr;
        ++items;
        if (front)
            rear->next = add;
        else
            front = add;
        return true;
    }

    bool dequeue(Customer & item)
    {
        if (front == nullptr)
            return false;
        item = front->item;
        --items;
        Node * temp = front;
        front = front->next;
        delete temp;
        if (items == 0)
            rear = nullptr;
        return true;
    }
};

#endif /* D4F134DD_CC03_4205_AB54_734D967E5BB0 */
