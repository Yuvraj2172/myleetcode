class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root == nullptr)return true;
        queue<TreeNode*> q;
        q.push(root);
        while(q.front()!=nullptr){
            TreeNode* f = q.front();
            q.pop();
            q.push(f->left);
            q.push(f->right);
        }
        while(!q.empty() && q.front() == nullptr){
            q.pop();
        }
        return q.empty();
    }
};