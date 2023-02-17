class Solution {
public:
    void helper(TreeNode* root , vector<int>&ans){
        if(root){
            helper(root->left,ans);
            ans.push_back(root->val);
            helper(root->right,ans);
        }
        return;
    }
    int minDiffInBST(TreeNode* root) {
       vector<int> ans;
        helper(root , ans);
        int m = INT_MAX;
        for(int i=0;i<ans.size()-1;i++){
            for(int j =i+1;j<ans.size();j++){
            m = min( abs(ans[i] - ans[j]), m );        
            }
        }
        return m;
    }
};