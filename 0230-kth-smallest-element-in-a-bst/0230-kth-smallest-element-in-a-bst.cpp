
class Solution {
public:
    
    void helper(TreeNode* root , int& ans , int& k){
        if(root == NULL)return;
        helper(root->left, ans , k);
         k--;
        if(k==0){
            ans = root->val;
            return ;
        }
       
        helper(root->right , ans ,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans =0;
        int cnt =0;
        helper(root , ans , k);
        return ans;
    }
};