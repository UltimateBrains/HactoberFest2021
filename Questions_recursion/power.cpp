//1. You are given a number x.
//2. You are given another number n.
//3. You are required to calculate x raised to the power n. Don't change the signature of power function

include<iostream>
using namespace std;

int powerLogarithmic(int x,int n){
    
   if(n == 0){
       
       return 1;
   } 
   
   int a = powerLogarithmic(x, n-1);
   int ans = a*a;
   
   if(n%2 == 1){
       
       ans = a * x;
   }
   
   return ans ;
}

int main(){
    
    int x,n; 
    cin>>x>>n;
    cout<<powerLogarithmic(x,n);
}