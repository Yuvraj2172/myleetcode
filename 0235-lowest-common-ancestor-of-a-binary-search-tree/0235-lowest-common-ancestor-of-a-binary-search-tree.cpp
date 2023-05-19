class Solution {
public:
    bool findpath(TreeNode* root , vector<int>& path , TreeNode* node){
        if(root== NULL)return false;
        path.push_back(root->val);
        if(root->val == node->val)return true;
        if(( root->left && findpath(root->left,  path , node)) || root->right && findpath(root->right, path, node)){
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> path1;
        vector<int> path2;
        findpath(root , path1 , p);
        findpath(root , path2, q);
        int i=0;
        for( i = 0; i < path1.size() && i < path2.size(); i++){
            if(path1[i]!= path2[i]){
                break;
            }
        }
    return new TreeNode(path1[i-1]);
    }
    
    
};