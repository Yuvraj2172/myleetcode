class Solution {
public:
    pair<int,int> helper(TreeNode* root, int& ans){
        if(!root)return {0,0};
        auto [ls,lc] = helper(root->left, ans);
        auto [rs,rc] = helper(root->right, ans);
        int cs = root->val + ls + rs;
        int cc = 1 + lc + rc;
        if(cs / cc == root->val)ans++;
        return {cs, cc};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans =0;
        helper(root, ans);
        return ans;
    }
};