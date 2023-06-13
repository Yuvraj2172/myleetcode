class BSTIterator {
    private :
    stack<TreeNode*> mystack;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* currNode = mystack.top();
        int currval = currNode->val;
        mystack.pop();
        pushAll(currNode->right);
        return currval;
    }
    
    bool hasNext() {
        return !mystack.empty();
    }
    void pushAll(TreeNode* root){
        for(; root!=NULL; mystack.push(root), root = root->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */