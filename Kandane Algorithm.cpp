/*By Harsh Sinha

Kandane Algorithm is a dynamic programming as well as greedy approch.

Intuition : It is used to find max or min subarray sum. According to Kandane each element
            can contribute to maximun subaaray sum till now or it will form a new subarray.
            For example arr[]={1,-2,3,-1,2};
            0-index: 1 will contribute to max subarray till now to it will form new.
                     As no subarray exits so it will form a new.
            1-index: -2 can contribute to pre subarray or it will from a new one.
                     if pre contribute, sum=1+(-2)=-1
                     if form new, sum=-2;
                     therfore it will contribute to pre subarray
            2-index: 3 can contribute to pre subarray or it will from a new one.
                     if pre contribute, sum=1+(-2)+3=2
                     if form new, sum=3;
                     therfore it will form new subarray.
            3-index: -1 can contribute to pre subarray or it will from a new one.
                     if pre contribute, sum=3+(-1)=2
                     if form new, sum=-1;
                     therfore it will contribute to pre subarray.
            4-index: 2 can contribute to pre subarray or it will from a new one.
                     if pre contribute, sum=3+(-1)+2=4
                     if form new, sum=2;
                     therfore it will contribute to pre subarray.
            so max subaary found is max({1,-1,2,4});

*/

#include <iostream>
using namespace std;

int Kandanes_algo_or_max_sum(int arr[],int n){
    int curr_sum=arr[0];
    int max_sum=arr[0];
    for(int i=1;i<n;i++){
        curr_sum=max(arr[i]+curr_sum,arr[i]);
        max_sum=max(curr_sum,max_sum);
    }
    
    return (max_sum<0)?0:max_sum;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    cout<<Kandanes_algo_or_max_sum(arr,n);
    return 0;
}
