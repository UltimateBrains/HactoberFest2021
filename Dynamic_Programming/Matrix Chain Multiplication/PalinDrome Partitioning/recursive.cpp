#include "bits/stdc++.h"
using namespace std ;

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

int solve(string s ,int i , int j)
{
    if(i>=j)
    return 0;

    if(isPalin(s,i,j))
    return 0; 

    int mn = INT_MAX ;
    for (int k = i; k < j; k++)
    {
        int temp = solve(s,i,k)+solve(s,k+1,j)+1 ;
        mn=min(mn,temp) ;
    }
    return mn ;
}

int main()
{
    string s ;
    cin>>s ;
    cout<<solve(s,0,s.length()-1) ;
}