class Solution:
    def countSquares(self, arr: List[List[int]]) -> int:
        m = len(arr)
        n = len(arr[0])

        dp = [[0] * n for _ in range(m) ]

        ans = 0 

        for i in range(m):
            dp[i][0] = arr[i][0]
            ans += dp[i][0]

        for j in range(1, n):
            dp[0][j] = arr[0][j]
            ans += arr[0][j]

        for i in range(1, m):
            for j in range(1,n):
                if arr[i][j] == 1:
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
                ans += dp[i][j]

        return ans