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
        for(int i=0; i<v.size()-1;i++){
          ans = min(ans, abs(v[i]- v[i+1]));
        }
        return ans;
    }
};