class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[n-1].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        for(int i= m-1; i>=0; i--){
            dp[n-1][i] = arr[n-1][i];
        }
        for(int i = n-2; i >=0; i--){
            for(int j = 0; j < arr[i].size(); j++){
                dp[i][j] = arr[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};



