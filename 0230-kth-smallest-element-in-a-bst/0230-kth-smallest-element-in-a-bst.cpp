class Solution {
public:
    vector<int> traversal;
    void helper(TreeNode* root){
        if(root == NULL)return;
        helper(root->left);
        traversal.push_back(root->val);
        helper(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root);
        return traversal[k-1];
    }
};