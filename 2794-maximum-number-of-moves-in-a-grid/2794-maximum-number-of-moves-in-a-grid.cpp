class Solution {
public:
    int helper(int row, int col, int prev, vector<vector<int>>& arr, int n, int m, vector<vector<int>>& dp){
        if(row < 0 || row >= n || col < 0 || col >= m )return 0;
        int currval = arr[row][col];
        if(currval <= prev)return 0;

        if(dp[row][col]!= -1)return dp[row][col];

        int r = helper(row, col+1, currval, arr, n,m, dp);
        int ld = helper(row+1, col+1, currval, arr, n,m,dp);
        int ud = helper(row-1, col+1, currval, arr, n,m, dp);

        dp[row][col] =  max({r, ld, ud});

        return 1 + dp[row][col];

    }
    int maxMoves(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans =0 ;
        for(int i=0; i<n;i++){
            ans = max(ans, helper(i,0,-1, arr, n,m,dp)-1);
        }
        return ans;
    }
};