class Solution {
public:
    int titleToNumber(string s) {
        long long  ans =0;
        for(auto it : s){
            ans = (ans*26) + it - 'A' + 1;
        }
        return ans;
    }
};