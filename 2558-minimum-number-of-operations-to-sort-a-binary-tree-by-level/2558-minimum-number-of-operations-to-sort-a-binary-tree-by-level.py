class Solution:
    def minSwaps(self, arr):
        mp = {}
        temp = sorted(arr)

        for i in range(len(arr)):
            mp[temp[i]] = i

        ans = 0
        i = 0
        while i < len(arr):
            ind = mp[arr[i]]
            if ind == i:
                i += 1
            else:
                arr[i], arr[ind] = arr[ind], arr[i]
                ans += 1
        return ans

    def minimumOperations(self, root):
        from collections import deque

        q = deque([root])
        ans = 0

        while q:
            size = len(q)
            temp = []

            for _ in range(size):
                node = q.popleft()
                temp.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

            ans += self.minSwaps(temp)

        return ans