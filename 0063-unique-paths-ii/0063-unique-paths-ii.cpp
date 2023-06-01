class Solution {
public:
    int helper(int m , int n , vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp){
        if((m>=0 && n>=0) && obstacleGrid[m][n]==1)return 0;
        if(m<0 || n<0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        if(m==0 && n==0)return 1;
        dp[m][n]= helper(m-1,n, obstacleGrid,dp) + helper(m, n-1, obstacleGrid,dp);
        return dp[m][n];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(),-1));
        int m = obstacleGrid.size()-1;
        int n = obstacleGrid[0].size()-1;
        return helper(m,n,obstacleGrid,dp);
    }
};