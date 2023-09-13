class Solution {
public:
    void helper(int open, int close , vector<string>& ans, string& op){
        if(!open && !close){
            ans.push_back(op);
            return;
        }
        if(open > 0){
            op+='(';
            helper(open -1 , close , ans , op);
            op.pop_back();
        }
        if(close > open){
            op+=')';
            helper(open , close -1 , ans, op);
            op.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = n , close = n;
        string op="";
        vector<string> ans;
        helper(open, close , ans , op);
        return ans;
    }
};