class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int tn = nums.size();
        sort(nums.begin(), nums.end());
        vector<unsigned long long > dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(int x : nums){
                if(i>=x)dp[i]+= dp[i-x];
                else break;
            }
        }
        return (int)dp[target];
    }
};