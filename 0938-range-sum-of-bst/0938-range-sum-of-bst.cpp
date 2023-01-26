class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }
    void helper(TreeNode* root, int low , int high , int& sum){
        if(root== NULL)return;
        if(root->val >= low && root->val<=high){
            sum+=root->val;
            helper(root->left, low, high, sum);
            helper(root->right , low ,high , sum);
        }
        else if(root->val <low){
            helper(root->right, low , high , sum);
        }
        else if(root->val > high){
            helper(root->left , low , high , sum);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        helper(root, low ,high , sum);
        return sum;
    }
};