class Solution {
public:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    void helper(TreeNode* root){
        if(!root)return;
        helper(root->left);
        if(prev!= NULL && (root->val < prev->val )){
            if(first  == NULL){
                first = prev;
                middle = root;
            }
            else { last = root ;}
        }
        prev = root;
        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        helper(root);
        if(first && last)swap(first->val, last->val);
        else if(first && middle)swap(first->val , middle->val);
        
    }
};