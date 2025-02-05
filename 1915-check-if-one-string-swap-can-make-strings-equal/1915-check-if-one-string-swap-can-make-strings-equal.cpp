class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        unordered_map<char,int> mp1, mp2;
        for(auto it : s1){
            mp1[it]++;
        }
        for(auto it : s2){
            mp2[it]++;
        }
        for(int i =0; i < n; i++){
            if(mp1[s1[i]]!=mp2[s1[i]])return false;
        }
        int c =0;
        for(int i =0 ; i < n; i++){
            if(s1[i]!=s2[i])c++;
        }
        return c <= 2;
    }
};