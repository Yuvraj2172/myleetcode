class Solution {
public:
    TreeNode* helper(vector<int>& preorder, int prestart , int preend, vector<int>& inorder, int instart , int inend){
        if(instart> inend || prestart > preend)return NULL;
        int rootdata = preorder[prestart];
        TreeNode* root = new TreeNode(rootdata);
        int k =-1;
        for(int i=instart;i<=inend; i++){
            if(inorder[i] == rootdata){
                k = i;
                break;
            }
        }
        root->left = helper(preorder, prestart +1 ,prestart + (k - instart) , inorder, instart, k-1);
        root->right= helper(preorder, prestart + ( k - instart)+1, preend , inorder, k+1, inend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int prestart =0;
        int preend  = preorder.size()-1;
        int instart =0;
        int inend=inorder.size()-1;
        return helper(preorder, prestart , preend, inorder, instart, inend);
    }
};