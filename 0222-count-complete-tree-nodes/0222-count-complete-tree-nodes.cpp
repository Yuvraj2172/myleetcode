class Solution {
public:
    void helper(TreeNode* root, int& ans){
        if(!root)return;
        helper(root->left, ans);
        ans++;
        helper(root->right, ans);
    }
    int countNodes(TreeNode* root) {
        int ans =0;
        helper(root,ans);
        return ans;
    }
};