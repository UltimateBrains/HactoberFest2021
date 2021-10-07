/*By Harsh Sinha

Question : Print all Subset of a string.

Intuition : For each character in string we have two option.
            Include character in subset or exclude it.
            We don't know when and which character to include
            or exclude.So recursion comes into play.
            
Recursion : There are three basic steps.
            1. Base case
            2. Calling own function
            3. Finally calculating ans
     Note : Steps 2 and 3 can be switched according to que i.e maybe
            first we calculate ans then call the function         
            
   For ex : s="abc",let curr=""
                         abc 
                     /          \
  index 0           ""            a
                  /      \       /    \
  index 1        ""        b     a     ab
               /    \    / \    / \   /  \
  index 2    ""     c   b   bc  a  ac ab  abc
  Note : all left node of each recursion tree are excluded one while right are included
  
  
*/


#include <bits/stdc++.h>
using namespace std;

void subset(string s,string curr,int i){
    //Base case when string gets over
    if(i==s.size()){
        cout<<curr<<" " ;
        return ;
    }
    //choose character
    subset(s,s[i]+curr,i+1);
    //not choose character
    subset(s,curr,i+1);
}

int main()
{
    string s,curr=" ";
    cin>>s;
    subset(s,curr,0);
    return 0;
}
