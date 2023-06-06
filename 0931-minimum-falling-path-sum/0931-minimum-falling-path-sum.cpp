class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n= matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<n; i++)dp[0][i] = matrix[0][i];
        for(int i=1; i<m;i++){
            for(int j=0;j< n ;j++){
                int u = matrix[i][j] + dp[i-1][j];
                int ld = matrix[i][j];
                if(j-1>=0)ld+= dp[i-1][j-1];else ld+= 1e8;
                int rd = matrix[i][j];
                if(j+1<n) rd+= dp[i-1][j+1]; else rd+= 1e8;
                dp[i][j] = min(u, min(ld, rd));
            }
        }
        int mini = 1e9;
        for(int j = 0; j<n;j++){
            mini = min(mini , dp[m-1][j]);
        }
        return mini;
    }
};