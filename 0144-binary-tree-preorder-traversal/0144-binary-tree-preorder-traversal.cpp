class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)return {};
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            int ele = node->val;
            ans.push_back(ele);
            if(node->right){
                st.push(node->right);
            }
            if(node->left)st.push(node->left);
        }
        return ans;
    }
};