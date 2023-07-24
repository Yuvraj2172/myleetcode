class Solution {
public:
    bool helper(int i , int j , string& s, string& p, vector<vector<int>>& dp){
        if(dp[i][j]!=-1)return dp[i][j];
        if(j== p.length()){
            dp[i][j] = (i==s.length())? 1:0;
            return dp[i][j];
        }
        bool firstmatch = (i<s.length() && (s[i]==p[j] || p[j]=='.'));
        if(j+1< p.length() && p[j+1]=='*'){
            dp[i][j] = ( helper(i, j+2, s,p,dp) || firstmatch && helper(i+1, j , s,p, dp)) ? 1:0;
        }
        else{
            dp[i][j] = firstmatch && helper(i+1, j+1, s,p, dp);
        }
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        int n = s.length() , m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return helper(0,0, s, p, dp);
    }
};