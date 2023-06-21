class Solution {
public:
    long long helper(vector<int>& nums , vector<int>& cost , int currentmid, int n){
        long long currentcost =0LL;
        for(int i=0 ; i < n;i++){
            currentcost += 1LL*abs(nums[i] - currentmid)*cost[i];
        }
        return currentcost;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        int left =nums[0], right=nums[0];
        for(auto it : nums){
            left = min(left , it);
            right = max(right , it);
        }
        long long ans =0;
            while(left < right){
                int mid = (left + right)/2;
                long long costmid = helper(nums, cost, mid,n);
                long long  costjustgreaterthanmid = helper(nums , cost , mid+1,n);
                if(costmid > costjustgreaterthanmid){
                    left = mid+1;
                    ans = costjustgreaterthanmid;
                }
                else {
                    right = mid;
                    ans = costmid;
                }
            }
        
        return ans;
    }
};