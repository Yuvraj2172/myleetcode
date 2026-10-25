from collections import deque
class Solution:
    def closedIsland(self, arr: list[list[int]]) -> int:
        m,n = len(arr), len(arr[0])
        ans = 0
        visited = [[False] * n for i in range(m)]

        dir = [(-1,0), (1,0), (0,1), (0,-1)]

        def bfs(row, col):
            queue = deque([[row,col]])
            visited[row][col] = True
            closed = True

            while queue:
                r,c = queue.popleft()
                if r == 0 or c == 0 or r == m-1 or c == n-1:
                    closed = False
                for dr, dc in dir:
                    nr, nc = r + dr, c + dc
                    
                    if (0 <= nr < m) and (0 <= nc < n) and (arr[nr][nc] == 0)and visited[nr][nc] == False:
                        visited[nr][nc] = True
                        queue.append([nr, nc])
            return closed
        
        for i in range(m):
            for j in range(n):
                if arr[i][j] == 0 and not visited[i][j]:
                    if bfs(i,j):
                        ans +=1
        return ans
