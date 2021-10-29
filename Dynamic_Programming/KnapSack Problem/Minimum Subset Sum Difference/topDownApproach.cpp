#include "bits/stdc++.h"
using namespace std ;

void subsetSum(int a[] ,int n ,int s , vector<vector<bool>> &t)
{
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < s+1; j++)
        {
            if(i==0)
            t[i][j] = false ;

            if(j==0)
            t[i][j] = true ;
        }
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < s+1; j++)
        {
            if(a[i-1] <=j)
            {
                t[i][j] = t[i-1][j-a[i-1]] || t[i-1][j] ; 
            }else
            {
                t[i][j] = t[i-1][j] ;
            }
        }
    }
}

int main()
{
    int n ;
    cin>>n ;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i] ;
    }
    int s =0 ;
    for (int i = 0; i < n; i++)
    {
        s=s+a[i] ;
    }
    vector<vector<bool>> t (n+1 , vector<bool> (s+1)) ;
    subsetSum(a,n,s,t) ;
    vector<int> final ;
    for(int j=0; j<=s/2; j++)
    {
        if(t[n][j])
        {
            final.push_back(j) ;
        }
    }
    int mn =INT_MAX;
    for (int i = 0; i < final.size(); i++)
    {
        mn = min(mn,s-2*final[i]) ;
    }
    cout<<mn<<endl ;
}