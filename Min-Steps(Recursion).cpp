/*By Harsh Sinha

Question : Given a number n. We have to reduce it to 1 in minimum steps and we have some
           options.
           1. At any step n can decrese by one i.e n->n-1
           2. At any step n can decrese by half if n is multiple of 2 i.e n->n/2
           3. At any step n can decrese by one-third if n is multiple of 3 i.e n->n/3

Intuition : As we have 3 choice and we have to optimise it as min steps
            are required. So basically we don't know which step should be
            first. Whenever we have choices and don't have idea, recursion
            take place.
            We will use all the steps and finally compare which has min
            steps.

Recursion : There are three basic steps.
            1. Base case
            2. Calling own function
            3. Finally calculating ans
     Note : Steps 2 and 3 can be switched according to que i.e maybe
            first we calculate ans then call the function

*/

#include <iostream>

using namespace std;

int minSteps(int n){
    //Base case : If n is 1 this means we don't have to reduce it further
    if(n==1){
        return 0;
    }
    
    // 3 ans as we have 3 steps and will be calculating for each steps
    //INT_MAX because it may happen ans2 and ans3 is not elegible  and we need min ans.
    
    int ans1=INT_MAX,ans2=INT_MAX,ans3=INT_MAX; 
    
    //calling function again as now n->n-1
    ans1=minSteps(n-1);    
    
    if(n%2==0){                                
        ans2=minSteps(n/2);   //calling function again as now n->n/2
    }
    if(n%3==0){
       ans3=minSteps(n/3);   //calling function again as now n->n/3
    }
    int final_ans=min(ans1,min(ans2,ans3));// taking min of all steps
  
    //as we take any step so it consume 1 step so we add 1
    return final_ans+1;  
}

int main()
{
    int n;
    cin>>n;
    cout<<minSteps(n);
    return 0;
}
