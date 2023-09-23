class helper{
  public :
  int maxi;
  int mini;
  bool isBST;
  int sum=0;
};
helper solve(TreeNode* root, int& ans){
  if(!root){
    return {INT_MIN, INT_MAX, true, 0};
  }
  helper left = solve(root->left,ans);
  helper right = solve(root->right, ans);
  helper currNode;
  currNode.sum = left.sum + right.sum + root->val;
  currNode.maxi = max(root->val, right.maxi);
  currNode.mini = min(root->val, left.mini);
  if(left.isBST && right.isBST && root->val > left.maxi && root->val < right.mini){
    currNode.isBST = true;
  }
  else{
    currNode.isBST = false;
  }
  if(currNode.isBST){
    ans = max(ans, currNode.sum);
  }
  return currNode;
}
class Solution {
public:
    int maxSumBST(TreeNode* root) {
      int ans = 0;
      helper temp = solve(root, ans);
      return ans;    
    }
};