#include<iostream>
using namespace std;
#define MAX 100
#include<chrono>


class Stack
{
    private: 
        int top;
        int S[MAX];

    public:
        Stack()
        {
            top = -1;
        }

        bool isFull()
        {
            if(this->top == MAX-1)
            {
                return true;
            }

            return false;
        }

        bool isEmpty()
        {   
            if(top == -1)
            {
                return true;
            }

            return false;
        }

        void push(int data)
        {
            if(isFull())
            {
                cout<<"Stack Overflow";
                return;
            }

            top++;
            S[top] = data;
        }

        int pop()
        {
            if(isEmpty())
            {
                cout<<"Stack Empty"<<endl;
                return -1;
            }
            
            return S[top--];
        }

        void getTop()
        {
            if(isEmpty())
            {
                cout<<"Stack Empty"<<endl;
                return;
            }

            cout<<"Top->"<<S[top]<<endl;
        }

        void print()
        {
            if(isEmpty())
            {
                cout<<"Stack is empty"<<endl;
                return;
            }

            for(int temp = top; temp>=0; temp--)
            {
                cout<<"<-"<<S[temp];
            }
            cout<<endl;
        }

        void reverse()
        {
            Stack S2, S3;

            while(!isEmpty())
            {
                S2.push(pop());
            }

            while(!S2.isEmpty())
            {
                S3.push(S2.pop());
            }

            while(!S3.isEmpty())
            {
                push(S3.pop());
            }
        }
};

void TOH(Stack &A, Stack &B, Stack &C, int n)
{
    if (n==1)
    {
        B.push(A.pop());
        return;
    }
    
    TOH(A, C, B, n-1);
    B.push(A.pop());
    TOH(C, B, A, n-1);
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    Stack s,sd,sa;
    s.push(6);
    s.push(5);
    s.push(4);
    // s.getTop();
    s.push(3);
    s.push(2);
    s.push(1);
    // s.getTop();
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

    // s.reverse();
    // s.print();

    TOH(s,sd,sa,6);
    s.print();
    sd.print();
    sa.print();

    return 0;
}