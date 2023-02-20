class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target> nums[nums.size()-1]) return nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target)return i;
        }
        int index =0;
        for(int i=0;i<nums.size()-1;i++){
         if(nums[i] < target && target < nums[i+1])
             index =i+1;
        }
        return index;
       
    }
};