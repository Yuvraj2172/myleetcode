class Solution {
public:
    string reverseVowels(string s) {
        vector<int> orig;
        int n = s.size();
        for(int i=0;i<n;i++){
            char c = s[i];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')orig.push_back(i);
        }
        vector<int> change = orig; reverse(change.begin(), change.end());
        for(int i=0;i<change.size()>>1;i++)swap(s[orig[i]],s[change[i]]);
        return s;
    }
};