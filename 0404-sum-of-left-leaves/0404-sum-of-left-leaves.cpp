class Solution {
public:
    void helper(TreeNode* root , int& ans){
      if(!root)return;
      if(root->left && root->left->left==NULL && root->left->right ==NULL)ans+=root->left->val;
      if(root->right)helper(root->right, ans);
      if(root->left)helper(root->left, ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans =0;
        helper(root , ans);
        return ans;
    }
};