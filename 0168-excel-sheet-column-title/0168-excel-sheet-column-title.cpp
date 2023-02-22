class Solution {
public:
    string convertToTitle(int n) {
        string str = "";
        while(n>0){
            char ch  = 'A' + (n-1)%26;
            str = ch + str;
            n = (n-1)/26;
        }
        return str;
    }
};