class Solution {
public:
    int helper(TreeNode* root , int currentsum){
        if(root == NULL)return 0;
        currentsum = currentsum*10 + root->val;
        if(root->left == NULL && root->right == NULL)return currentsum;
        int leftsum = helper(root->left , currentsum);
        int rightsum = helper(root->right , currentsum);
        return leftsum + rightsum;
    }
    int sumNumbers(TreeNode* root) {
        int currentsum=0;
        return helper(root , currentsum);
    }
};