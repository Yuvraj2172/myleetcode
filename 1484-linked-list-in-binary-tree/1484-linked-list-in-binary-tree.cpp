
class Solution {
public:
    bool dfs(ListNode*head, TreeNode* root){
        if(!head)return 1;
        if(!root || root->val != head->val)return false;

        return dfs(head->next, root->left) || dfs(head->next, root->right) ;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root)return false;

        if(dfs(head, root)){
            return 1;
        }

        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }


};