
class Solution {
public:
    int findparent(TreeNode* root , int& parent , int val , int height){
    if(root == NULL)return 0;
    if(root->val == val)return height;
    parent = root->val;
        int left = findparent(root->left , parent , val , height+1);
    if(left!=0)return left;
    parent = root->val;
        int right = findparent(root->right , parent , val ,height+1);
        return right;        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL)return false;
        if(root->val == x || root->val ==y)return false;
        
        int xparent = -1;
        int xheight = findparent(root , xparent , x ,0);
        
        int yparent = -1;
        int yheight = findparent(root , yparent , y,0);
        
        if(xparent!=yparent && xheight == yheight)return true;
        return false;
    }
};