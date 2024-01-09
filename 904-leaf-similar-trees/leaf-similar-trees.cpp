class Solution {
public:
    void f(TreeNode* root, vector<int>& v){
        if(!root)return;
        if(!root->left && !root->right)v.push_back(root->val);
        f(root->left,v);
        f(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        vector<int> b;
        f(root1, a);
        f(root2,b);
        return (a==b) ? true : false;
    }
};