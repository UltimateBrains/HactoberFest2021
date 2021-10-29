#include "bits/stdc++.h"
using namespace std ;

int t[202][202][2] ;

int solve(string s ,int i ,int j ,bool isTrue)
    {
        if(i>j)
        return 0 ;
        
        if(i==j)
        {
            if(isTrue)
            {
                return s[i]=='T'?1:0 ;
            }else
            {
                return s[i]=='F'?1:0 ;
            }
        }
        
        if(t[i][j][isTrue] != -1)
        {
            return t[i][j][isTrue] ;
        }
        
        int ans =0 ;
        for(int k=i+1 ; k<j ; k+=2)
        {
            int lt ,rt,lf,rf ;
            
            
            if(t[i][k-1][1] != -1)
            {
                lt = t[i][k-1][1] ;
            }else
                lt = solve(s,i,k-1,true) ;
            
            if( t[i][k-1][0] != -1)
            {
                lf = t[i][k-1][0] ;
            }else
                lf = solve(s,i,k-1,false) ;
            
            if(t[k+1][j][1] != -1)
            {
                rt = t[k+1][j][1] ;
            }else
                rt = solve(s,k+1,j,true) ;
            
            if(t[k+1][j][0] != -1)
            {
                rf = t[k+1][j][0] ;
            }else
               rf = solve(s,k+1,j,false) ;
            
            if(s[k]=='&')
            {
                if(isTrue)
                {
                    ans+=lt*rt ;
                }
                else
                {
                    ans+=lt*rf+lf*rt+lf*rf ;
                }
                
            }
            else if(s[k]=='|')
            {
                if(isTrue)
                {
                    ans+=lt*rt + lt*rf + lf*rt ;
                }
                else
                {
                    ans+=lf*rf ;
                }
            
                
            }
            else if(s[k]=='^')
            {
                if(isTrue)
                {
                    ans+=lt*rf+rt*lf ;
                }
                else
                {
                    ans+=lt*rt + rf*lf ;
                }
            }
            
        }
        return t[i][j][isTrue] = ans%1003 ;
    }

int main()
{
    string s ;
    cin>>s ;
    memset(t,-1,sizeof(t)) ;
    cout<<solve(s,0,s.length()-1,true) ;
}