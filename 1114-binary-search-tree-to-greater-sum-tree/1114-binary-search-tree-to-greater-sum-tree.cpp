class Solution {
public:
    int treesum(TreeNode* root){
      if(!root)return 0;
      return treesum(root->left) + root->val + treesum(root->right);
    }
    void altertree(TreeNode* root , int& sum){
      if(!root)return;
      altertree(root->left,sum);
      int temp = root->val;
      root->val = sum;
      sum-= temp;
      altertree(root->right, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 
        treesum(root);
        altertree(root,sum);
        return root;
    }
};