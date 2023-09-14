class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> in, pre, post;
      stack<pair<TreeNode*, int>> st;
      if(!root)return {};        
      st.push({root,1});
      while(!st.empty()){
        
        auto it = st.top(); st.pop();
        if(it.second == 1){
          pre.push_back(it.first->val);
          it.second++;
          st.push(it);
          if(it.first->left){
            st.push({it.first->left,1});
          }
        }
        else if(it.second ==2){
          in.push_back(it.first->val);
          it.second++;
          st.push(it);
          if(it.first->right){
            st.push({it.first->right, 1});
          }
        }
        else{
          post.push_back(it.first->val);
        }
      }
      return in;
    }
};