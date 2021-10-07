// --- CYCLIC SORT ---

// When to use? 
// If you have an array of adjacent numbers and you need to sort it.
// Like you have randomly written numbers from 1 to n and want to sort it  

// LOGIC:
// Say you have numbers from 1 to n and want to sort it 
// Interate over the array (taking i = 0) and if value at position i is not i+1 replace number at that 
// position with number at "arr[i]+1" position. Do this until the number at "i" position is "i + 1".   

// SAMPLE QUESTION:
// Chef's friend given him an array of size n-1 integers and these integers are in the range of 1 to n. There 
// are no duplicates in array. One of the integers is missing in the array.Now chef has to write efficient code 
// to find the missing integer. Please help him to find the missing number.

// SOLUTION:

#include<iostream>

using namespace std;

void solve(int a[])
{
    // implement cyclic sort 
    int i = 0;
    while(i<5)
    {
        if(a[i] == i+1 || a[i] == 6) i++;
        else {
            int temp = a[i];
            a[i] = a[a[i]-1];
            a[a[i]-1] = temp;
        }
    }

    // find missing number now
    i = 0;
    // if all number from 1 to n-1 present answer is n i.e 6 itself  
    int flag = 6; 
    while (i<5)
    {
        if(a[i] == i+1) { i++; continue;}
        else { flag = i+1; break;}
    }
    cout<<"missing number -- "<<flag;
}

int main(){

    // TEST CASE --- n = 6 and elements are 1,2,3,5,6
    int a[] = {1,2,3,5,6};
    solve(a);

    return 0;
}

