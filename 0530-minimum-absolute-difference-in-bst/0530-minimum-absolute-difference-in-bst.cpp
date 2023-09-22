class Solution {
public:
    vector<int> v;
    void helper(TreeNode* root){
      if(!root)return;
      helper(root->left);
      v.push_back(root->val);
      helper(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        helper(root);
        sort(v.begin(), v.end());
        int ans = 1e9+7;
        for(int i=0; i<v.size();i++){
          for(int j = i+1; j<v.size();j++){
            ans = min(ans, v[j] - v[i]);
          }
        }
        return ans;
    }
};