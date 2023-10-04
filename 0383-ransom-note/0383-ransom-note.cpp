class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char,int> mp;
        for(auto it : m)mp[it]++;
        for(auto it : r){
            if(mp.find(it)!=mp.end() && mp[it]>0)mp[it]--;
            else return false;
        }
        return 1;
    }
};