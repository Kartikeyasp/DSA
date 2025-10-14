#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
    
        Node()
        {
            this->data = 0;
            next = NULL;
        }

        Node(int data)
        {
            this->data = data;
            next = NULL;
        }
};

class stack
{
    public:
        Node *top;

        stack()
        {
            this->top = NULL;
        }

        bool isEmpty()
        {
            if(this->top == NULL)
            {
                return true;
            }
        
            return false;
        }
        
        void push(int data)
        {
            Node *newNode = new Node(data);
            newNode->next = this->top;
            this->top = newNode;
        }
        
        void pop()
        {
            if(isEmpty())
            {
                cout<<"Stack Empty"<<endl;
                return;
            }
        
            Node *temp = this->top;
            this->top = this->top->next;
            cout<<"Popped "<<temp->data<<endl;
            delete temp;
        }
        
        void print()
        {
            if(isEmpty())
            {
                cout<<"Stack is empty"<<endl;
                return;
            }
        
            Node *temp = this->top;
            while(temp!= NULL)
            {
                cout<<"<-"<<temp->data;
                temp = temp->next;
            }
            cout<<endl;
        }
        
        void getTop()
        {
            if(isEmpty())
            {
                cout<<"Stack is empty"<<endl;
                return;
            }
        
            cout<<"Top->"<<this->top->data<<endl;
        }

        void reverse()
        {
            
        }
};


int main()
{
    stack s;
    s.push(6);
    s.push(2);
    s.push(7);
    s.getTop();
    s.push(1);
    s.push(8);
    s.push(5);
    s.getTop();
    s.print();
    
    // s.getTop();
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    // s.getTop();
    // s.pop();
    // s.pop();
    // s.pop();
    // s.print();

    return 0;
}