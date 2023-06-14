class Solution {
public:
    void helper(TreeNode* root , vector<int>& traversal){
        if(!root)return;
        helper(root->left , traversal);
        traversal.push_back(root->val);
        helper(root->right , traversal);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> traversal;
        helper(root , traversal);
        int start =0;
        int end = traversal.size()-1;
        while(start< end){
            if(traversal[start] + traversal[end] == k)return 1;
            else if(traversal[start] + traversal[end] > k)end--;
            else start++;
        }
        return 0;
    }
};