class Solution {
public:
    vector<int> v;
    void inorder(TreeNode* root){
      if(!root)return;
      inorder(root->left);
      v.push_back(root->val);
      inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        TreeNode* newRoot = new TreeNode(-1);
        TreeNode* temp = newRoot;
        for(auto it : v){
          TreeNode* newNode = new TreeNode(it);
          temp->right = newNode;
          temp = newNode;
        }
        return newRoot->right;
    }
};