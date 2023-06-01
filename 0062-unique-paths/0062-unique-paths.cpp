class Solution {
public:
    int helper(int m , int n , vector<vector<int>>&dp){
        if(m==0 || n==0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        if(m==1 && n==1 )return 1;
        dp[m][n] = helper(m-1, n , dp) + helper(m, n-1, dp);
        return dp[m][n];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return helper(m,n,dp);
        
    }
};