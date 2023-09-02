class Solution {
public:
    int helper(string& s, vector<string>& dict, vector<int>& dp,  unordered_map<string,int>& mp,int ind){
        if(ind>= s.size())return 0;
        if(dp[ind]!= -1)return dp[ind];
        string currstr = ""; int ans =  s.size();
        for(int currind = ind; currind < s.size();currind++){
            currstr.push_back(s[currind]);
            int count = (mp.count(currstr) ? 0 : currstr.size())+ helper(s, dict , dp ,mp, currind+1);
            ans = min(ans, count);
        }
        return dp[ind] = ans;
    }
    int minExtraChar(string s, vector<string>& dict) {
        vector<int> dp(s.size(),-1);
        unordered_map<string,int> mp;
        for(auto it : dict){
            mp[it]++;
        }
        return helper(s, dict , dp,mp, 0);
    }
};