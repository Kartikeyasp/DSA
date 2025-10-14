#include<iostream>
using namespace std;

int rec_name(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n*rec_name(n-1);
    }
}

int main()
{
    //Printing name N times using reccrursion
    cout<<rec_name(4);
}