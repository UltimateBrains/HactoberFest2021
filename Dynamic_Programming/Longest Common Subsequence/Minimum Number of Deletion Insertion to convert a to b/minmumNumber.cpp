#include "bits/stdc++.h"
using namespace  std ;

int main()
{
    int x,y ;
    cin>>x>>y ;
    string s1,s2 ;
    fflush(stdin) ;
    cin>>s1>>s2 ;
    int t[x+1][y+1] ;
    for (int i = 0; i < x+1; i++)
    {
        for (int j = 0; j < y+1; j++)
        {
            if(i==0 || j==0)
            t[i][j] =0 ;
        }
    }
    for (int i = 1; i < x+1; i++)
    {
        for (int j = 1; j < y+1; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                t[i][j] = t[i-1][j-1]+1 ;
            }else
            {
                t[i][j] = max(t[i-1][j],t[i][j-1]) ;
            }
        }
    }
    cout<<x-t[x][y]+y-t[x][y]<<endl ;
}