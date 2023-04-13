class Solution {
public:
    int findMin(vector<int>& nums) {
        int left= 0;
        int right = nums.size()-1;
        int ans = nums[0];
        while(left<=right){
            if(nums[left]<nums[right]){
                ans = min(ans , nums[left]);
                break;
            }
            int mid = left + (right - left)/2;
            ans = min (nums[mid], ans);
            if(nums[mid]>= nums[left]){
                left = mid+1;
            }
            else right = mid-1;
        }
        return ans;
    }
};