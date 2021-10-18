#include "bits/stdc++.h"
using namespace std ;

bool subset(int a[] ,int n ,int sum)
{
    if(n==0)return false ;
    if(sum==0)return true ;

    if(a[n-1] <= sum)
    {
        return subset(a,n-1,sum-a[n-1]) || subset(a,n-1,sum) ;
    }
    return subset(a,n-1,sum) ;
}

int main()
{
    
}