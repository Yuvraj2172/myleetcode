from math import ceil

dp = [[-1] * 201 for _ in range(201)]

class Solution:
    def dfs( self , A , B ) :
        A = int(A)
        B = int(B)
        if A <= 0 and B > 0 :
            return 1.0
        if A <= 0 and B <= 0 :
            return 0.5
        if A > 0 and B <= 0 :
            return 0.0
        if dp[A][B] != -1 :
            return dp[A][B]
        ans = 0.25 * (
            self.dfs( A - 4 , B ) +
            self.dfs( A - 3 , B - 1 ) +
            self.dfs( A - 2 , B - 2 ) +
            self.dfs( A - 1 , B - 3 )
        )
        dp[A][B] = ans
        return ans

    def soupServings( self , n ) :
        if n > 5000 :
            return 1.0
        for i in range(201) :
            for j in range(201) :
                dp[i][j] = -1
        N = int( ceil( n / 25.0 ) )
        return self.dfs( N , N )