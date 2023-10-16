class Solution {
public:
    vector<int> getRow(int n) {
        n++;
        vector<vector<int>> dp(n);
        for(int i=0; i<n;i++){
            dp[i].resize(i+1);
            for(int j=0; j<=i;j++){
                if(j==0 || j ==i)dp[i][j] = 1;
                else {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
            }
        }
        vector<int> ans;
        for(int j = 0; j< dp[n-1].size(); j++){
            ans.push_back(dp[n-1][j]);
        }
        return ans;
    }
};