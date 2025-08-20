from typing import List

class Solution:
    def countSquares(self, arr: List[List[int]]) -> int:
        m, n = len(arr), len(arr[0])
        dp = [[0] * n for _ in range(m)]
        ans = 0

        for i in range(m):
            for j in range(n):
                if arr[i][j] == 1:
                    dp[i][j] = 1 if i == 0 or j == 0 else 1 + min(
                        dp[i-1][j], dp[i][j-1], dp[i-1][j-1]
                    )
                    ans += dp[i][j]
        return ans
