class Solution {
public:
    int helper(string s ,string t, int**ans){
        int m = s.size();
        int n = t.size();
        if(m==0 || n==0){
            return max(m,n);
        }
        if(ans[m][n]!=-1){
        return ans[m][n];    
        }
        int finalans;
        if(s[0] == t[0]){
            return helper(s.substr(1), t.substr(1), ans);
        }else {
            int a = helper(s.substr(1) , t, ans)+1;
            int b = helper(s, t.substr(1) , ans) + 1;
            int c = helper(s.substr(1), t.substr(1) , ans)+1;
            finalans = min(a, min(b,c));
        }
        ans[m][n] = finalans;
        return finalans;
    }
    int minDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        int **ans = new int*[m+1];
        for(int i=0;i<=m;i++){
            ans[i] = new int[n+1];
            for(int j=0;j<=n;j++){
                ans[i][j] = -1;    
            }
        }
        return helper(s,t,ans);
    }
};