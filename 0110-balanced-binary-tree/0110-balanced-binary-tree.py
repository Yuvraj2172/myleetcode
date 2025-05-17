class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def do_dfs(root):
            if not root:
                return [True,0]
            left, right = do_dfs(root.left), do_dfs(root.right)

            balanced = left[0] and right[0] and abs(left[1] - right[1])<=1 

            return [balanced, 1 + max(left[1], right[1])]
        return do_dfs(root)[0]