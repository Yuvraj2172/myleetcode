class Solution {
public:
        long long mx = -10000000000;  
    vector<vector<long long>> dp;
    long long solve(vector<int>& a, vector<int>& b, int i, int j){
        if(i >= a.size()) return 0;
        if(j >= b.size()) return mx;
        if(dp[i][j] != mx) return dp[i][j];
        long long res = (long long)a[i]* (long long)b[j] + solve(a, b, i+1, j+1);
        res = max(res, solve(a, b, i, j+1));
        return dp[i][j] = res;
    } 
    long long maxScore(vector<int>& a, vector<int>& b) {
        dp.resize(5, vector<long long>(100001, mx) );
        return solve(a, b, 0, 0);
    }
};