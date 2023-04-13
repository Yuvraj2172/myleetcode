class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size()-1;
        int slow = 0;
        int fast = n;
        int water =0;
        while(slow < fast){
            water = max( water , (fast - slow)*(min(nums[fast] , nums[slow])));
            if(nums[slow] < nums[fast]) slow++;
            else fast--;
        }
        return water;
    }
};