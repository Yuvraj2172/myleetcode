class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0];
        string last = strs[n-1];
        string ans="";
        for(int i=0;i<first.size();i++){
            if(first[i] == last[i])ans+=first[i];
            else break;
        }
        return ans;
    }
};