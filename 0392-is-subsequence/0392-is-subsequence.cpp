class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size())return 0;
        int c =0;
        for(int i=0; i<t.size(); i++){
            if(t[i] == s[c]){
                c++;
            }
        }
        return c == s.size();
    }
};