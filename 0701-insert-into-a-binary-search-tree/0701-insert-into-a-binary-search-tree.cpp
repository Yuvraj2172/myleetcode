class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
        TreeNode* rootAns = new TreeNode(val);
            return rootAns;
        }
        if(root-> val < val)root->right  =insertIntoBST(root->right , val);
        if(root->val > val) root->left = insertIntoBST(root->left , val);
        return root;
    }
};