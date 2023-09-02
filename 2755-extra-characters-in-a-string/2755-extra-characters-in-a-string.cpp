class Solution {
public:
    int helper(string s, unordered_map<string, int>& mp, int ind, vector<int>& dp){
        if(ind>= s.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        string currstr = "";
        int ans = s.size();
        for( int i = ind ; i<s.size();i++){
            currstr.push_back(s[i]);
            int count = (mp.count(currstr) ? 0 : currstr.size()) + helper(s, mp , i+1, dp);
            ans = min(ans , count);
        }
        return dp[ind] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size(), -1);
        unordered_map<string, int> mp;
        for(auto it : dictionary)mp[it]++;
        return helper(s, mp,0, dp);
    }
};