class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        MOD = 10 ** 9 + 7
        dp = [0] * (n+1)
        dp[0] = 1
        for i in range(1,n+1):
            p = pow(i,x)
            if p > n:
                break
            for j in range(n, p - 1, -1):
                dp[j] = (dp[j] + dp[j - p]) % MOD
        return dp[n]
                

