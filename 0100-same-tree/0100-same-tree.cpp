class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p== NULL and q== NULL)return true;
        if(p== NULL or q == NULL)return false;
        return isSameTree(p->right, q->right) and isSameTree(p->left, q->left) and (p->val == q->val) ;
    }
};