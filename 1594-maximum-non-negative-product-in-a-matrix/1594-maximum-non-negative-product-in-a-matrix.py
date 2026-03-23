class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        row, cols, MOD = len(grid), len(grid[0]), 10 ** 9 + 7

        max_dp = [[0] * cols for _ in range(row)]
        min_dp = [[0] * cols for _ in range(row)]

        max_dp[0][0] = min_dp[0][0] = grid[0][0]

        for j in range(1, cols):
            max_dp[0][j] = max_dp[0][j-1] * grid[0][j]
            min_dp[0][j] = min_dp[0][j-1] * grid[0][j]
        for i in range(1, row):
            max_dp[i][0] = max_dp[i-1][0] * grid[i][0]
            min_dp[i][0] = min_dp[i-1][0] * grid[i][0]

        for i in range(1, row):
            for j in range(1, cols):
                val = grid[i][j]

                possible_values = [
                    max_dp[i][j-1] * val,
                    max_dp[i-1][j] * val,
                    min_dp[i][j-1] * val,
                    min_dp[i-1][j] * val
                ]

                max_dp[i][j] = max(possible_values)
                min_dp[i][j] = min(possible_values)
        
        ans = max_dp[-1][-1]
        return ans % MOD if ans >=0 else -1