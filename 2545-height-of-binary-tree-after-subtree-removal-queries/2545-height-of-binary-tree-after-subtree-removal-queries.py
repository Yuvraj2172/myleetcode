class Solution:
    def __init__(self):
        self.mp1 = {}
        self.mp2 = {}
        self.sz = {}
        self.id = 0
    
    def treeQueries(self, root: Optional[TreeNode], q: List[int]) -> List[int]:
        self.dfs(root, 0)
        left = [0] * self.id
        right = [0] * self.id
        
        for i in range(self.id):
            left[i] = self.mp2[i]
            if i > 0:
                left[i] = max(left[i - 1], left[i])
        
        for i in range(self.id - 1, -1, -1):
            right[i] = self.mp2[i]
            if i + 1 < self.id:
                right[i] = max(right[i], right[i + 1])
        
        ans = []
        for node in q:
            nodeid = self.mp1[node]
            l, r = nodeid, nodeid + self.sz[nodeid] - 1
            h = 0
            if l > 0:
                h = max(h, left[l - 1])
            if r + 1 < self.id:
                h = max(h, right[r + 1])
            ans.append(h)
        
        return ans
    
    def dfs(self, root: Optional[TreeNode], h: int) -> int:
        if not root:
            return 0
        self.mp1[root.val] = self.id
        self.mp2[self.id] = h
        self.id += 1
        lz = self.dfs(root.left, h + 1)
        rz = self.dfs(root.right, h + 1)
        self.sz[self.mp1[root.val]] = 1 + lz + rz
        return 1 + lz + rz
        