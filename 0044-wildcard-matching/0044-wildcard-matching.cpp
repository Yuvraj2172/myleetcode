class Solution {
public:
    bool solve(int i , int j, string& s, string& p, vector<vector<int>>& dp, int n , int m){
        if(i>= n && j>=m)return 1;
        if(j>=m)return 0;
        if(i>=n){
            for(int k =j;k<m;k++){
                if(p[k]!='*')return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        bool ans = false;
        if(s[i] == p[j] || p[j] == '?'){
            ans = solve(i+1,j+1, s, p , dp, n , m);
            // dp[i][j] = ans;
        }
        else if(p[j]=='*'){
            for(int k=i; k<=n;k++){
                ans = ans || solve(k , j+1, s, p, dp, n ,m);
            }
        }
        return dp[i][j] = ans;
    
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n, vector<int>(m , -1));
        return solve(0,0,s,p,dp,n,m);
    }




};