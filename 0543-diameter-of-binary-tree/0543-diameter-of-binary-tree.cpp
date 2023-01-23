
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    pair<int,int> helper(TreeNode* root){
        if(root == NULL){
        pair<int, int> p ;
            p.first = 0;
            p.second = 0;
            return p;
        }
        pair<int, int> leftAns = helper(root->left);
        pair<int, int> rightAns = helper(root->right);
        int lh = leftAns.first;
        int rh = rightAns.first;
        int ld = leftAns.second;
        int rd= rightAns.second;
        int height = 1 + max(lh, rh);
        int diameter = max(lh+ rh , max(ld , rd));
        pair<int,int> ans;
        ans.first = height;
        ans.second = diameter;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
       return helper(root).second;
    }
};