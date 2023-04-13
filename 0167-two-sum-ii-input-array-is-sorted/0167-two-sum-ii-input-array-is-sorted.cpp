class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        int slow = 0;
        int fast = nums.size()-1;
        while(slow< fast){
            int sum = nums[slow] + nums[fast];
            if(sum < target)slow++;
            else if(sum > target)fast--;
            else return {slow+1, fast+1};
        }
        return {-1,-1};
    }
};