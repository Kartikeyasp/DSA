#include<iostream>
using namespace std;
#define MAX 100

class Queue
{
private:
    int Q[MAX];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }

        return false;
    }
    
    bool isFull()
    {
        if (rear == MAX - 1)
        {
            return true;
        }

        return false;
    }
    
    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }

        return front;
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }

        return rear;
    }


    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue Full" << endl;
            return;
        }

        if (isEmpty())
        {
            front++;
            rear++;
            Q[rear] = data;
            return;
        }

        rear++;
        Q[rear] = data;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty";
            return -1;
        }

        int temp;

        if (front == rear)
        {
            temp = Q[front];
            front = -1;
            rear = -1;
        }
        else
        {
            temp = Q[front];
            front++;
        }

        return temp;
    }


    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "<-Front ";
        for (int i = front; i <= rear; i++)
        {
            cout << Q[i] << " ";
        }

        cout << "<-Rear" << endl;
    }

};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.print();
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    q.dequeue();
    q.dequeue();

    q.print();
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    q.enqueue(50);
    q.enqueue(60);

    q.print();
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    q.dequeue();
    q.dequeue();

    q.print();
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    return 0;
}