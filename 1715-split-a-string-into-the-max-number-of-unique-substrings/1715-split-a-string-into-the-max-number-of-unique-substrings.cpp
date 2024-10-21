class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return helper(0,s, st);
    }

    int helper(int start, string s, unordered_set<string> st){
        if(start == s.size())return 0;

        int tempans = 0;
        for(int i = start + 1; i <= s.size(); i++){
            string ss = s.substr(start,i - start);

            if(st.find(ss) == st.end()){
                st.insert(ss);
                tempans = max(tempans, 1 + helper(i,s,st));
                st.erase(ss);
            }
        }
        return tempans;
    }
};