class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto it : arr)mp[it]++;
        vector<int> v;
        unordered_set<int> s;
        for(auto it : mp){
            v.push_back(it.second);
            s.insert(it.second);
        }
        return s.size() == v.size();
    }
};