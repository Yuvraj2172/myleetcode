class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=0;
        int repeated = -1, missing = -1;
        unordered_map<int,int> mp;
        vector<int> v;
        for(auto it : grid){
            for(auto i : it){
                mp[i]++;
                n++;
            }
        }
        for(auto it : mp){
            if(it.second == 2){
                if(repeated == -1){
                    repeated = it.first;
                }
            }
        }
        for(int i = 1; i<=n;i++){
            if(mp.find(i) == mp.end()){
                missing = i;
            }
        }
        return {repeated, missing};
    }
};