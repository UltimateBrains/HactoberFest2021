#include<bits/stdc++.h>
using namespace std;
bool subset(vector<int>nums,int x){
	vector<vector<int>>result={{}};
	for(int x:nums){
            int n=result.size();
            for(int i=0;i<n;++i){
                vector<int>r=result[i];
                r.push_back(x);
                result.push_back(r);
            }
        }
	for(int i=0;i<result.size();i++){
		cout<<"{";
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<",";
		}
		cout<<"}"<<endl;
	}
	int sum=0;
	for(int i=0;i<result.size();i++){
		sum=0;
		for(int j=0;j<result[i].size();j++){
			sum=sum+result[i][j];
		}
		if(sum==x){
			return true;
		}
	}
	return false;
}
int main(){
vector<int>v={10,8,7,6};
	cout<<subset(v,16);
}
