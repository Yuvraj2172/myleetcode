class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int firstrotationsum=0;
        int sum=0;
        for(int i=0; i<nums.size();i++){
            firstrotationsum = firstrotationsum+ i*nums[i];
            sum += nums[i];
        }
        int ans = firstrotationsum;
        int temp=ans;
        for(int i=1;i<nums.size();i++){
            temp = temp + sum - nums.size()*nums[nums.size()-i];
            ans = max(temp, ans);
        }
    return ans;
    }
    
};