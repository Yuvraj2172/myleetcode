class Solution {
public:
    string replaceDigits(string s) {
        for(int i=1; i<s.length(); i+=2){
            int temp = s[i] - '0';
            s[i] = s[i-1] + temp;
        }
        return s;
    }
};