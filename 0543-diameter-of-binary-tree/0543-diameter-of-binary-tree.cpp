class Solution {
public:
    int ans = -(1e9 + 7);
    int height(TreeNode* root){
      if(!root)return 0;
      return 1 + max(height(root->left), height(root->right));
    }
    void dia(TreeNode* root){
      if(!root)return;
      int lh = height(root->left);
      int rh = height(root->right);
      ans = max(ans , lh + rh);
      dia(root->left);
      dia(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dia(root);
        return ans;
    }
};