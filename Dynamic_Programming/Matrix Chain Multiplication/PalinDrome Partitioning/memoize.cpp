#include "bits/stdc++.h"
using namespace std ;

int t[1002][1002] ;

bool isPalin(string s ,int i ,int j)
{
    while(i<j)
    {
        if(s[i]==s[j])
        {
            i++ ;
            j-- ;
        }else
        {
            return false ;
        }
    }
    return true ;
}

int solve(string s ,int i ,int j)
{
    if(i>=j)
    return 0 ;

    if(isPalin(s,i,j))
    {
        return 0 ;
    }

    if(t[i][j] != -1)
    return t[i][j] ;

    int mn = INT_MAX ;
    for(int k=i ; k<j ;k++)
    {
        int t = solve(s,i,k) + solve(s,k+1,j) + 1 ;
        mn=min(mn,t) ;
    }
    return t[i][j] = mn ;
}

int main()
{
    memset(t,-1,sizeof(t)) ;
    string s ;
    cin>>s ;
}