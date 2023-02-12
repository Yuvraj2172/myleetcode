class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans =0;
        sort(nums.begin() , nums.end());
        auto beg = nums.begin();
        auto end = nums.end();
        for(int i=0;i< nums.size()-1;i++){
        ans += upper_bound( beg + i+1 , end , upper - nums[i] ) - lower_bound( beg + i +1 , end ,lower - nums[i]);
        }
        return ans;
    }
};