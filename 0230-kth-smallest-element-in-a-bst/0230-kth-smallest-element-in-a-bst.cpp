class Solution {
public:
    void helper(TreeNode* root , int& k , int& ans){
        if(!root)return;
        helper(root->left , k ,ans);
        k--;
        if(k==0){
            ans = root->val;
        }
        helper(root->right, k , ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans =0;
        helper(root , k , ans);
        return ans;
    }
};