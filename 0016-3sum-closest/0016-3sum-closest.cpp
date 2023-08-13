class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans=0;
        int currmin =INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int left =i+1;
             int right = n-1;
            while(left < right){
                int sum = nums[i] + nums[left]+ nums[right];
                if(abs(sum - target) < currmin){
                    ans = sum;
                    currmin = abs(sum - target);
                }
                if(sum < target)left++;
                else right--;
            }
        }
        return ans;
    }
};