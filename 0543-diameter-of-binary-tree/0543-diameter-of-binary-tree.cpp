
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int height(TreeNode* root){
    if(root == NULL)return 0;
    return 1 + max(height(root->left) , height(root->right));
        }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)return 0;
        int option1 = height(root->left) + height(root->right);
        int option2 = diameterOfBinaryTree(root->left);
        int option3 = diameterOfBinaryTree(root->right);
        int temp = max(option1 , option2);
        return max(temp , option3);
    }
};