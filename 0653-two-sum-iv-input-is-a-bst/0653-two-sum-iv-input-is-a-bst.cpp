/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root , vector<int>& ans){
        if(!root)return;
        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right , ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> traversal;
        helper(root , traversal);
        int n = traversal.size();
        for(int i=0; i < n-1 ; i++){
            for(int j = i+1;j < n;j++){
                if(traversal[i] + traversal[j] == k)return 1;
            }
        }
     return 0;
    }
   
};