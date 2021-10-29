#include "bits/stdc++.h"
using namespace std ;

int knapsack(int wt[] ,int val[] ,int n ,int w)
{
    if(n==0 || w==0)return 0 ;

    if(wt[n-1] <=w)
    {
        return max(val[n-1] + knapsack(wt,val,n-1,w-wt[n-1]) , knapsack(wt,val,n-1,w)) ;
    }

    return knapsack(wt,val,n-1,w) ;
}