class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        for(int i=0; i<nums.size(); i++){
            if(find(nums.begin(), nums.end(), -nums[i])!= nums.end()){
                ans = max(ans , nums[i]);
            }
        }
        return ans;
    }
};