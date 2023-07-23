class Solution {
public:
    void helper(TreeNode* root , vector<int>& ans , int level){
        if(root == NULL)return;
        if(ans.size() == level)ans.push_back(root->val);
        level+=1;
        helper(root->right, ans , level);
        helper(root->left, ans , level);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(root , ans , 0);
        return ans;
    }
};