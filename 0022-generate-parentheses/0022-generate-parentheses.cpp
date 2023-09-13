class Solution {
public:
    void helper(int cnt1, int cnt2, int n, vector<string>& ans, string& op, int ind){
        if(ind>=2*n){
            ans.push_back(op);
            return;
        }
        if(cnt1 < n && ind < 2*n - 1){
             op+='(';
            helper(cnt1 +1, cnt2, n , ans, op, ind+1);
            op.pop_back();
        }
        if(cnt1 > cnt2 and ind > 0){
             op+=')';
            helper(cnt1, cnt2 + 1, n, ans ,op, ind+1);
            op.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string op="";
        vector<string> ans;
        helper(0,0,n,ans,op,0);
        return ans;
    }
};