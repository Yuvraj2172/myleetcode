class Solution {
public:
    bool helper(TreeNode* root , int targetSum , int sum){
        if(root == NULL)return false;
        if(root->left == NULL && root->right == NULL){
            sum+= root->val;
            if(sum == targetSum)return true;
        }
        return helper(root->left , targetSum , sum + root->val) or helper(root->right , targetSum , sum + root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
     int sum=0;
        return helper(root , targetSum , sum);
    }
};