class Solution {
public:
    void helper(int ind, vector<string>& s, string& res , vector<string>& ans){
        int n = s.size();
        if(ind== n){
            ans.push_back(res);
            return;
        }
        int m = s[ind].size();
        for(int i=0;i<m;i++){
            res.push_back(s[ind][i]);
            helper(ind+1, s , res , ans);
            res.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        string arr[] = {"0", "0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n = digits.size();
        vector<string> ans;
        string res;
        vector<string> s;
        for(int i=0;i<n;i++){
            int num = digits[i]- '0';
            s.push_back(arr[num]);
        }
        helper(0 , s , res , ans);
        return ans;
    }
};