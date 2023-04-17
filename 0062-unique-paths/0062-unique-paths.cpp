class Solution {
public:
     int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n));
        return helper(dp, 0,0,m,n);
    }
     int helper(vector<vector<int>>& dp, int i, int j, int m , int n){
        if(i>=m || j>=n)return 0;
        if(i==m-1 || j==n-1)return 1;
        if(dp[i][j]) return dp[i][j];
        return dp[i][j]=helper(dp, i+1, j,m,n) + helper(dp ,i , j+1,m,n);
    }
   
    // int m=m, n=n;
   
    
};