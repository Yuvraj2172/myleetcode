class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int fast = nums.size()-1;
       int slow =0;
        while(slow< fast){
            int sum = nums[slow] + nums[fast]; 
            if(sum > target){
                fast--;
            }
            else if( sum < target){
                slow++;
            }else {
                return {slow+1, fast+1};
            }
        }
        
        return {-1,-1};
    }
};