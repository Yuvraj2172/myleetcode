class Solution {
public:
    bool helper(TreeNode* root , long long minval , long long maxval){
        if(root == NULL)return true;
        if(root->val >= maxval || root->val <= minval)return false;
        return helper(root->left , minval , root->val) && helper(root->right , root->val , maxval);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root , LLONG_MIN, LLONG_MAX);
    }
};