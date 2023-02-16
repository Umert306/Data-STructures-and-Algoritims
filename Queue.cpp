#include <iostream>
using namespace std;

template <class x>
class Queue
{
private:
    struct QueueNode
    {
        x value;
        QueueNode *next;
    };

    QueueNode *front;
    QueueNode *rear;
    int numItems;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
        numItems = 0;
    }

    void Enqueue(x key)
    {
        QueueNode *newnode = new QueueNode;
        newnode->value = key;
        newnode->next = NULL;
        if (isEmpty())
        {
            front = newnode;
            rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
        numItems++;
    }

    x Dequeue()
    {
        QueueNode *temp;
        x val;
        if (isEmpty())
        {
            cout << "The queue is empty \n";
        }
        else
        {
            val = front->value;
            temp = front->next;
            delete front;
            front = temp;
            numItems--;
        }
        return val;
    }

    bool isEmpty()
    {
        if (numItems)
            return false;
        else
            return true;
    }

    void makeNull()
    {
        while (!isEmpty())
            Dequeue();
    }

    ~Queue()
    {
        makeNull();
    }
};

int main()
{
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.Enqueue(6);
    q.Enqueue(7);
    q.
}