class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i= 0;i<n;i++){
        dp[m-1][i] = triangle[m-1][i];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                dp[i][j] = triangle[i][j] + min(dp[i+1][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
    }

};