#include<iostream>
using namespace std;
#define MAX 100

class twoStack
{
    private:
        int top1,top2;
        int S[MAX];

    public:
        twoStack()
        {
            top1 = -1;
            top2 = MAX;
        }

        bool isEmpty1()
        {
            if(top1 == -1)
            {
                return true;
            }

            return false;
        }

        bool isEmpty2()
        {
            if(top2 == MAX)
            {
                return true;
            }

            return false;
        }

        bool isFull()
        {
            if(top1 + 1 == top2)
            {
                return true;
            }

            return false;
        }

        void push1(int data)
        {
            if(isFull())
            {
                cout<<"Stack overflow"<<endl;
                return;
            }

            top1++;
            S[top1] = data;
        }

        void push2(int data)
        {
            if(isFull())
            {
                cout<<"Stack overflow"<<endl;
                return;
            }

            top2--;
            S[top2] = data;
        }

        void pop1()
        {
            if(isEmpty1())
            {
                cout<<"Stack empty"<<endl;
                return;
            }

            cout<<"Popped:"<<S[top1]<<endl;
            top1--;
        }

        void pop2()
        {
            if(isEmpty2())
            {
                cout<<"Stack empty"<<endl;
                return;
            }

            cout<<"Popped:"<<S[top2]<<endl;
            top2++;
        }

        void getTop1()
        {
            if(isEmpty1())
            {
                cout<<"Stack empty"<<endl;
                return;
            }

            cout<<"Top:"<<S[top1]<<endl;
        }

        void getTop2()
        {
            if(isEmpty2())
            {
                cout<<"Stack empty"<<endl;
                return;
            }

            cout<<"Top:"<<S[top2]<<endl;
        }

        void print1()
        {
            if(isEmpty1())
            {
                cout<<"Stack empty"<<endl;
                return;
            }

            for(int temp = top1; temp>=0; temp--)
            {
                cout<<"<-"<<S[temp];
            }

            cout<<endl;
        }

        void print2()
        {
            if(isEmpty2())
            {
                cout<<"Stack empty"<<endl;
                return;
            }

            for(int temp = top2; temp<MAX; temp++)
            {
                cout<<"<-"<<S[temp];
            }

            cout<<endl;
        }

};

int main()
{

    twoStack S;
    S.push1(10);
    S.push1(20);
    S.push2(30);
    S.push2(40);

    S.print1();
    S.print2();

    S.pop1();
    S.pop2();

    S.getTop1();
    S.getTop2();
    return 0;
}