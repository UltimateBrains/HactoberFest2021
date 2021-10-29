#include "bits/stdc++.h"
using namespace std ;

int main()
{
    int n,m ;
    cin>>n>>m ;
    string s1 ,s2 ;
    fflush(stdin) ;
    cin>>s1>>s2 ;
    int t[n+1][m+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            if(i==0 || j==0)
            {
                t[i][j] =0 ;
            }
        }
    }
    for (int i = 1; i < n+1 ; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                t[i][j] = 1+t[i-1][j-1] ;
            }else
            {
                t[i][j] = max(t[i-1][j] , t[i][j-1]) ;
            }
        }
    }

    string ans = "" ; 
    int i =m,j =n ;
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            ans+=s1[i-1] ;
            i-- ;
            j-- ;
        }else
        {
            if(t[i-1][j] > t[i][j-1])
            {
                ans+=s1[i-1] ;
                i-- ;
            }else 
            {
                ans+=s2[j-1] ;
                j-- ;
            }
        }
    }

    while(j>0)
    {
        ans+=s2[j-1] ;
        j-- ;
    }
    
    while(i>0)
    {
        ans+=s1[i-1] ;
        i-- ;
    }
    
    reverse(ans.begin(),ans.end()) ;
    cout<<ans<<endl ;
}