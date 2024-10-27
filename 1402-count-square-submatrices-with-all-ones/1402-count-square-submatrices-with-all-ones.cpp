class Solution {
public:
    int countSquares(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();

        int ans = 0;

        vector<vector<int>> dp(m, vector<int>(n,0));

        for(int i=0; i<m;i++){
            dp[i][0] = arr[i][0];
            ans += arr[i][0];
        }

        for(int j = 1; j<n;j++){
            dp[0][j] = arr[0][j];
            ans += arr[0][j];
        }

        for(int i = 1; i<m;i++){
            for(int j = 1; j<n;j++){
                if(arr[i][j] == 1){
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                    
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }

};