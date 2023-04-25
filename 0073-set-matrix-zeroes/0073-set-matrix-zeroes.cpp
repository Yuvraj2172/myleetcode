class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        vector<pair<int, int>> v;
        int m = nums.size();
        int n = nums[0].size();
        for(int i=0; i<m;i++){
            for(int j = 0; j < n;j++){
                if(nums[i][j]==0){
                    v.push_back({i ,j});
                }
            }
        }
        // for(auto it : v)cout<<it.first<<" "<<it.second<<"\n";
        for(auto it : v){
            for(int i= 0 ; i<m;i++){
                nums[i][it.second] =0;
            }
            for(int j = 0; j<n;j++){
                nums[it.first][j] = 0;
            }
        }
    }
};