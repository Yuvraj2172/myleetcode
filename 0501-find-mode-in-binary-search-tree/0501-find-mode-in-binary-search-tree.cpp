class Solution {
public:
    void inorder(TreeNode* root, unordered_map<int,int>& mp){
        if(!root)return;
        inorder(root->left, mp);
        mp[root->val]++;
        inorder(root->right, mp);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        inorder(root,mp);
        int occ= INT_MIN;
        for(auto it : mp){
            if(it.second > occ)occ = it.second;
        }
        vector<int> ans;
        for(auto it : mp){
            if(it.second == occ){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};