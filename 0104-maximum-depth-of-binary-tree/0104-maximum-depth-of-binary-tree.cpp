class Solution {
public:
    int maxHeight(TreeNode* node){
        if(node == NULL)return 0;
        int lh = maxHeight(node->left);
        int rh = maxHeight(node->right);
        return 1+max(lh,rh);
    }
    int maxDepth(TreeNode* root) {
        if(root== NULL)return 0;
        return 1+ max(maxHeight(root->left),maxHeight(root->right));
    }
};