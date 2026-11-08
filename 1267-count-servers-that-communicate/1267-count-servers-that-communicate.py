class Solution:
    def countServers(self, arr: list[list[int]]) -> int:
        m , n = len(arr), len(arr[0])
        row = [0] * m
        col = [0] * n

        ans = 0

        for i in range(m):
            for j in range(n):
                if arr[i][j]:
                    row[i]+=1
                    col[j] +=1
        
        for i in range(m):
            for j in range(n):
                if arr[i][j] and (row[i] > 1 or col[j] > 1):
                    ans +=1
        return ans