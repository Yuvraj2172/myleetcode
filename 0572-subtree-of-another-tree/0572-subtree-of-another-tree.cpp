class Solution {
public:
    bool isSymmetric(TreeNode* root , TreeNode* subRoot){
       if(root == NULL && subRoot== NULL)return true;
        if(root == NULL || subRoot == NULL)return false;
        if(root->val != subRoot->val) return false;
        return isSymmetric(root->left, subRoot->left) && isSymmetric(root->right , subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)return false;
        if(root->val == subRoot->val){
            bool ans = isSymmetric(root , subRoot);
            if(ans)return true;
        }
        bool left = isSubtree(root->left , subRoot);
        bool right = isSubtree(root->right, subRoot);
        return left || right;
    }
};