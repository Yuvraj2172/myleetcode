class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int temp = nums[0], ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            temp = nums[i] > nums[i-1] ? temp + nums[i] : nums[i];
            ans = max(ans, temp);
        }
        return ans;
    }
};