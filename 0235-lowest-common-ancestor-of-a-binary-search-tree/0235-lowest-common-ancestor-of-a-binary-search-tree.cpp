class Solution {
public:
    bool findPath(TreeNode* root , vector<int>& path , TreeNode* p){
        if(root == NULL)return false;
        path.push_back(root->val);
        if(root->val == p->val)return true;
        if((root->left && findPath(root->left , path , p)) || (root->right && findPath(root->right , path , p))){
            return true;            
        }
        
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> path1 ;
        vector<int> path2;
        
        if(!findPath(root , path1 , p) || !findPath(root , path2 , q))return new TreeNode(-1);
        int i;
        for(i =0 ; i < path1.size() && i <  path2.size() ; i++){
            if(path1[i]!=path2[i]){
                return new TreeNode(path1[i-1]);
               break;
            }
        }
    
        return new TreeNode(path1[i-1]);
    }
};