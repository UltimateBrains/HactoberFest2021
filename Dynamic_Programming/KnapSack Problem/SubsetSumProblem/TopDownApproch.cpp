#include "bits/stdc++.h"
using namespace std ;

int main()
{
    int n ,sum ;
    cin>>n ;
    int a[n] ;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i] ;
    }
    cin>>sum ;
    bool t[n+1][sum+1] ;
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(i==0)t[i][j] =false ;
            if(j==0)t[i][j] = true ;
        }
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if(a[i-1]<=j)
            {
                t[i][j] = t[i-1][j-a[i-1]] || t[i-1][j] ;
            }else
            {
                t[i][j] = t[i-1][j] ;
            }
        }
    }
        cout<<t[n][sum]<<endl ;
}