class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> scopy = strs;
        vector<pair<string,int>> s;
        for(int i =0; i<strs.size(); i++){
            sort(strs[i].begin(), strs[i].end());
            s.push_back({strs[i],i});
        }
        unordered_map<string, vector<int>> mp;
        for(auto it : s){
            mp[it.first].push_back(it.second);
        }
        vector<vector<string>> ans;
        for(auto it : mp){
            vector<string> temp;
            for(auto i : it.second){
                temp.push_back(scopy[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};