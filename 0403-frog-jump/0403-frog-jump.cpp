class Solution {
public:
    bool solve( vector<int>& stones, int i , int jump, vector<vector<int>>& dp){
        if(i == stones.size()-1)return true;
        if(i>= stones.size())return false;
        if(dp[i][jump]!= -1)return dp[i][jump];
        bool onejump = false, zerojump = false, prevjump = false;
        if(mp.find(stones[i] + jump + 1)!= mp.end())
            onejump = solve(stones, mp[stones[i] + jump + 1], jump + 1 , dp);
        if(mp.find(stones[i] + jump)!= mp.end())
            zerojump = solve(stones, mp[stones[i] + jump], jump, dp);
        if(mp.find(stones[i] + jump - 1)!= mp.end() && jump > 1)
            prevjump = solve(stones, mp[stones[i] + jump - 1], jump -1 ,dp);
        return dp[i][jump] = onejump || zerojump || prevjump;
    }
    unordered_map<long long, int> mp;
    bool canCross(vector<int>& stones) {
       for(int i=0; i< stones.size();i++){
           mp[stones[i]] = i;
       }
       if(stones[0] + 1 != stones[1])return false;
       vector<vector<int>> dp(stones.size()+1, vector<int>(stones.size()+1, -1));
       return solve(stones, 1, 1, dp);
    }
}; 