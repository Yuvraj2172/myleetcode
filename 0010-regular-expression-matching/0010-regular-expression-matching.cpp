class Solution {
public:
    bool dp(int i ,int j , string& s , string& p , vector<vector<int>>& memo){
        if(memo[i][j] !=-1)return memo[i][j];
        if(j== p.length()){
            memo[i][j] = (i==s.length()) ? 1:0;
            return memo[i][j];
        }
        bool firstmatch = (i<s.length() && (s[i] == p[j] || p[j] == '.'));
        if(j+1< p.length() && p[j+1] == '*'){
            memo[i][j] = (dp(i,j+2, s,p,memo) || (firstmatch && dp(i+1, j , s,p, memo))) ? 1:0;
        }
        else{
            memo[i][j] = (firstmatch && dp(i+1, j+1 , s,p,memo)) ? 1:0;
        }
        return memo[i][j];
    }
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<int>> memo(m+1, vector<int>(n+1,-1));
        return dp(0,0, s,p,memo);
    }
};