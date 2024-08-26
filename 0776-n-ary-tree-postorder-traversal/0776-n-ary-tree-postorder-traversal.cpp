class Solution {
public:
    void helper(Node* root, vector<int>& v){
        if(!root)return;

        for(int i=0; i<root->children.size(); i++){
            helper(root->children[i], v);
        }
        v.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> v;
        helper(root,v);
        return v;
    }
};