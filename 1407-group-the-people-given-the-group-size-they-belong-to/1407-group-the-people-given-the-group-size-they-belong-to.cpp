class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;
        int n = arr.size();
        for(int i=0; i<n;i++){
            int size = arr[i];
            mp[size].push_back(i);
            if(mp[size].size() == size){
                ans.push_back(mp[size]);
                mp[size].clear();
            }
        }
        return ans;
    }
};