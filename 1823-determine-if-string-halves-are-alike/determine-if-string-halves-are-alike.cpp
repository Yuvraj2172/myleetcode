class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels = {
            'a', 'e','i','o','u'
        };
        int vc =0;
        int mid = s.size()/2;
        for(int i=0; i<mid; i++){
            char a = (char)tolower(s[i]);
            char b = (char)tolower(s[i+ mid]);
            if(vowels.count(a))vc++;
            if(vowels.count(b))vc--;
        }
        return vc ==0;
    }
};