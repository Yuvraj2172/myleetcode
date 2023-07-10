class Solution {
public:
    int helper(TreeNode* root){
        if(!root)return INT_MAX;
        if(!root->left && !root->right)return 1;
        return 1 + min(helper(root->left) , helper(root->right));
    }
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        return helper(root);
    }
};