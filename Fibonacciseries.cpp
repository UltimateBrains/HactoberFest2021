#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n>=0&&n <= 1)
        return n;
        else
    return fib(n-1) + fib(n-2);
}

int main ()
{
    int n ;
    cout<<"enter which position number you want"<<endl;
    cin>>n;
    cout << fib(n);
    getchar();
    return 0;
}
