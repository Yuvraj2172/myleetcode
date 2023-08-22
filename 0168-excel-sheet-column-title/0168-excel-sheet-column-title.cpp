class Solution {
public:
    string convertToTitle(int n) {
        string ans="";
        while(n>0){
            char ch = 'A' + (n-1)%26;
            ans = ch + ans;
            n=(n-1)/26;
        }
        return ans;
    }
};