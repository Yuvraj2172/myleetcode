class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size ;i++){
                TreeNode* fr = q.front();
                q.pop();
                level.push_back(fr->val);
                if(fr->left!=NULL) q.push(fr->left);
                if(fr->right!=NULL) q.push(fr->right);

            }
            ans.push_back(level);
        }
        return ans;
    }
};