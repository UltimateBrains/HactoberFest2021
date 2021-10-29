class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int>v;
        stack<pair<int,int>>s;
        int n=t.size();
       
        for(int i=n-1;i>=0;i--){
    
               while(!s.empty() && s.top().first<=t[i]){
               s.pop();
               }
    
               if(s.empty()){
               v.push_back(0);
               }
               else{
               v.push_back(s.top().second-i);
               }

             s.push({t[i],i});
            }
        reverse(v.begin(),v.end());
        return v;
    }
};
