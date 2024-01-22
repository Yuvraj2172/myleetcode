class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()==1)return 0;
        sort(begin(nums), end(nums));
        int diff = nums[1] - nums[0];
        int n = nums.size();
        for(int i=1; i<n;i++){
            diff = max(diff, nums[i] - nums[i-1]);
        }
        return diff;
    }
};