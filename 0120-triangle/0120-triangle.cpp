class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size()-1;
        int n = triangle[m].size()-1;
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int j=0;j<=n;j++){
            dp[m][j] = triangle[m][j];
        }
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};