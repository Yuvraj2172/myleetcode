class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> uwu;
        unordered_map<int,int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        while(!mp.empty()){
            vector<int> temp, toErase;
            for(auto &[f,s] : mp){
                temp.push_back(f);
                s--;
                if(s==0)toErase.push_back(f);
            }
            uwu.push_back(temp);
            for(auto it : toErase){
                mp.erase(it);
            }
        }
        return uwu;
    }
};