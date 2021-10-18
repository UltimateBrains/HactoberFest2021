#include "bits/stdc++.h"
using namespace std ;

int t[1002][1002] ;

int lcs(int x ,int y , string s1 , string s2)
{
    if(x==0 || y==0)
    return 0 ;

    if(t[x][y] !=-1)
    return t[x][y] ;

    if(s1[x-1]==s2[y-1])
    {
        return t[x][y] = lcs(x-1,y-1,s1,s2)+1 ;
    }else
    {
        return t[x][y] = max(lcs(x-1,y,s1,s2) , lcs(x,y-1,s1,s2)) ;
    }
}

int main()
{
    int x,y ;
    cin>>x>>y ;
    string s1,s2 ;
    fflush(stdin) ;
    cin>>s1>>s2 ;
    memset(t,-1,sizeof(t)) ;
    cout<<lcs(x,y,s1,s2)<<endl ;
}