class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0
        
        rows, cols = len(grid), len(grid[0])
        MOD = 10**9 + 7
        dp = [[[0, 0] for _ in range(cols)] for _ in range(rows)]
        dp[0][0] = [grid[0][0], grid[0][0]]
        
        # Fill first column
        for i in range(1, rows):
            val = grid[i][0]
            dp[i][0][0] = dp[i-1][0][0] * val
            dp[i][0][1] = dp[i-1][0][1] * val
        
        # Fill first row
        for j in range(1, cols):
            val = grid[0][j]
            dp[0][j][0] = dp[0][j-1][0] * val
            dp[0][j][1] = dp[0][j-1][1] * val
        
        # Fill rest
        for i in range(1, rows):
            for j in range(1, cols):
                val = grid[i][j]
                
                if val >= 0:
                    dp[i][j][0] = min(dp[i-1][j][0], dp[i][j-1][0]) * val
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i][j-1][1]) * val
                else:
                    dp[i][j][0] = max(dp[i-1][j][1], dp[i][j-1][1]) * val
                    dp[i][j][1] = min(dp[i-1][j][0], dp[i][j-1][0]) * val
        
        max_prod = dp[-1][-1][1]
        return max_prod % MOD if max_prod >= 0 else -1