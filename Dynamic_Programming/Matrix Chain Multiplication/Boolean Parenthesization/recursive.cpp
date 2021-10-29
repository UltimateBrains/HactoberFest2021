#include "bits/stdc++.h"
using namespace std ;

int solve(string s ,int i ,int j ,bool isTrue)
{
    if(i>j)
    return 0 ;

    if(i==j)
    {
        if(isTrue)
        return s[i]=='T' ;
        else
        return s[i]=='F' ;
    }
    int ans =0 ;
    for (int k = i+1; k < j; k++)
    {
        int lt = solve(s,i,k-1,true) ;
        int lf = solve(s,i,k-1,false) ;
        int rt = solve(s,k+1,j,true) ;
        int rf = solve(s,k+1,j,false) ;

        if(s[k]=='&')
        {
            if(isTrue)
            {
                ans+=lt*rt ;
            }else
            {
                ans+= lt*rf + rt*lf + lf*rf ;
            }
        }else if(s[k]=='|')
        {
            if(isTrue)
            {
                ans+=lt*rt + lt*rf + lf*rt ;
            }else
            {
                ans+=lf*rf ;
            }
        }else if(s[k]=='^')
        {
            if(isTrue)
            {
                ans+=lt*rf + rt*lf ;
            }else 
            {
                ans+=lt*rt + lf*rf ;
            }
        }
    }
    return ans ;
}

int main()
{
    string s ;
    cin>>s ;
    cout<<solve(s,0,s.length()-1,true) ;
}