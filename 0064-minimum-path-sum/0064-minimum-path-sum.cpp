class Solution {
public:
    int helper(int m , int n , vector<vector<int>>& grid, vector<vector<int>>&dp){
        if(m==0 && n==0)return grid[m][n];
        if(m<0 || n<0)return 201;
        if(dp[m][n]!=-1)return dp[m][n];
        int up = grid[m][n]+helper(m-1,n, grid,dp);
        int left = grid[m][n]+helper(m, n-1, grid,dp);
        dp[m][n]= min(up, left);
        return dp[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size()-1;
        int n =  grid[0].size()-1;
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return helper(m , n , grid, dp);
    }
};