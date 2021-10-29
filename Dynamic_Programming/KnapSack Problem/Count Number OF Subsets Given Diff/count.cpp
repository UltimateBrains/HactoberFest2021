#include"bits/stdc++.h"
using namespace std ;

int countSubset(int a[] ,int n ,int s)
{
    int t[n+1][s+1] ;
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < s+1; j++)
        {
            if(i==0)
            t[i][j] = 0 ;

            if(j==0)
            t[i][j] =1 ;
        }
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < s+1; j++)
        {
            if(a[i-1] <=j)
            {
                t[i][j] = t[i-1][j-a[i-1]]+t[i-1][j] ;
            }else
            {
                t[i][j] = t[i-1][j] ;
            }
        }
    }
    return t[n][s] ;
}

int main()
{
    int n ;
    cin>>n ;
    int a[n] ;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i] ;
    }
    int diff ;
    cin>>diff ;
    int s =0 ;
    for (int i = 0; i < n; i++)
    {
        s=s+a[i] ;
    }
    int ss = (diff+s)/2 ;
    cout<<countSubset(a,n,ss)<<endl ;
}
 