class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL)return 0;
        return 1 + max(maxDepth(root->left) , maxDepth(root->right));
    }
};