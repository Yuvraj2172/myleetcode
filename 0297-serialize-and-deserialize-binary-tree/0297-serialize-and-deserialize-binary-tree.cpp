class Codec {
public:
    string serialize(TreeNode* root) {
       string s="";
        if(!root)return "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* fr = q.front();
            q.pop();
            if(fr==NULL)s.append("#,");
            else {
                s.append(to_string(fr->val)+',');
            }
            if(fr!=NULL){
                q.push(fr->left);
                q.push(fr->right);
            }
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode *root= new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            getline(s,str, ',');
            if(str=="#")node->left = NULL;
            else {
                TreeNode *leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str=="#")node->right = NULL;
            else {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));