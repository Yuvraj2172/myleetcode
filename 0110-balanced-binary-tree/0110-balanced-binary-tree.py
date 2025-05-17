
class Solution:
    ans = True
    def helper(self, root):
        if self.ans == False:
            return 0 
        if root is None:
            return 0
        left_check = self.helper(root.left)
        right_check = self.helper(root.right)

        if abs(left_check - right_check) > 1:
            self.ans = False
        return 1 + max(left_check, right_check)
        
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.helper(root)
        return self.ans