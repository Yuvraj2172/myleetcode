class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> level;
            for(int i=0;i<s;i++){
                TreeNode* child = q.front();
                q.pop();
                if(child->left)q.push(child->left);
                if(child->right)q.push(child->right);
                level.push_back(child->val);
            }
            ans.push_back(level);
        }
        int asize = ans.size();
            for(int i=0;i<asize;i++){
             if(i%2!=0) {
                 reverse(ans[i].begin() , ans[i].end());
             }    
            }
        return ans;
    }
};