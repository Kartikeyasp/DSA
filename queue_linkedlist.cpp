#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;

        Node()
        {
            data = 0;
            next = NULL;
        }

        Node(int data)
        {
            this->data = data;
            next = NULL;
        }
};

class Queue
{
    private:
        Node *front;
        Node *rear;

    public:
        Queue()
        {
            front = NULL;
            rear = NULL;
        }

        bool isEmpty()
        {
            if(front == NULL &&  rear == NULL)
            {
                return true;
            }

            return false;
        }

        void enqueue(int data)
        {
            Node *newNode = new Node(data);
            if(isEmpty())
            {
                front = newNode;
                rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = rear->next;
            }
        }

        int dequeue()
        {
            if(isEmpty())
            {
                return -1;
            }

            Node *temp = front;
            
            if(front == rear)
            {
                temp = front;
                front = NULL;
                rear = NULL;
            }
            else
            {
                temp = front;
                front = front->next;
            }
            int tempdata;
            tempdata = temp->data;
            delete temp;
            return tempdata;
        }

        void print()
        {
            if(isEmpty())
            {
                cout<<"Queue is empty"<<endl;
                return;
            }

            Node *temp = front;

            cout<<"<-Front";
            while(temp != rear)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<temp->data;
            cout<<"<-Rear";
        }
};

int main()
{
    Queue q;

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.print();
    cout << endl;

    cout << "Dequeued: " << q.dequeue() << endl; 
    q.print();
    cout << endl;

    cout << "Dequeued: " << q.dequeue() << endl; 
    q.print();
    cout << endl;

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    cout << "Dequeued: " << q.dequeue() << endl; 
    cout << "Dequeued: " << q.dequeue() << endl; 

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    cout << "Dequeued from empty queue: " << q.dequeue() << endl; 
    return 0;
}