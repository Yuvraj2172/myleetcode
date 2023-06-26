class Solution {
public:
    int helper(int ind , int target , vector<int>& coins, vector<vector<int>>& dp){
        if(ind<0){
            if(target ==0)return 1; 
            else return 0;
        }
        if(dp[ind][target]!=-1)return dp[ind][target];
        int nontake = helper(ind-1 , target , coins,dp);
        int take = 0;
        if(coins[ind]<= target){
            take = helper(ind , target - coins[ind], coins,dp);
        }
        return dp[ind][target]=take + nontake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1 , vector<int>(amount+1,-1));
        int ans =helper(n-1 , amount, coins, dp);
        return ans;
    }
};