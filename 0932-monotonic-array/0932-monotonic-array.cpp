class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool isincreasing = true, isdecreasing= true;
        if(n<=1)return 1;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i]){
                isincreasing = false;
                break;
            }
        }
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                isdecreasing = false;
                break;
            }
        }
        return isincreasing || isdecreasing;

    }
};