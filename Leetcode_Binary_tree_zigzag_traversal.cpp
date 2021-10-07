/*

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

*/
class Solution {
public:
    
   void solve(TreeNode* root,vector<vector<int>>&v){
        
       if(!root)
           return ;
       
       queue<TreeNode*>q;
       q.push(root);
       bool ltr=true;
       
       while(!q.empty()){
          
           int s=q.size();
           vector<int>level(s);
           
           
           for(int i=0;i<s;i++){
               TreeNode* node=q.front();
               q.pop();
               
               
                   
               int index=(ltr)?i:(s-i-1);
               level[index]=node->val;
                   
               if(node->left) q.push(node->left);
               if(node->right) q.push(node->right);
               
              }
           
           ltr=!ltr;
           
           v.push_back(level);
       }
           
    }
      
    
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>v;
        solve(root,v);
        return v;
    }
};
