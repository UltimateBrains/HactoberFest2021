//Bubble Sorting an array
#include<iostream>
using namespace std;
void bubble_sort(int *a,int n)
{
	int i,j, swapped;
	for(i=0;i<n-1;i++)
	{
		swapped=false;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				swapped=true;
			}
		}
		if(swapped==false)
		break;
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	int n;
	cout<<"Enter the number of elements in the array\n";
	cin>>n;
	int a[n],i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Sorted array is\n";
	bubble_sort(a,n);	
	return 0;
}
