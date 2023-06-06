class Solution {
public:
    int helper(int m , int i , int j , vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i==m)return triangle[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int down = triangle[i][j] + helper(m , i+1, j, triangle, dp);
        int diag = triangle[i][j] + helper(m, i+1, j+1, triangle, dp);
        dp[i][j] = min(down , diag);
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int i = triangle.size()-1;
        vector<vector<int>> dp(i+1,vector<int>(triangle[i].size()+1,-1));
        return helper(i , 0 , 0 , triangle, dp);
    }
};