class Solution {
public:
    void inorder(TreeNode* root , vector<TreeNode*>& v){
      if(!root)return;
      inorder(root->left,v);
      v.push_back(root);
      inorder(root->right,v);
    }
    TreeNode* buildTreeUtils(vector<TreeNode*>& v, int start, int end){
      if(start > end)return NULL;
      int mid = (start + end)>>1;
      TreeNode* root = v[mid];
      root->left = buildTreeUtils(v,start, mid-1);
      root->right = buildTreeUtils(v,mid+1, end);
      return root;

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root, v);
        int n = v.size();
        return buildTreeUtils(v,0,n-1);

    }
};