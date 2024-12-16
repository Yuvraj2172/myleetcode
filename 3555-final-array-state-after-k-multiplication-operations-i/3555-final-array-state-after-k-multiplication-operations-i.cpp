class Solution {
public:

    int helper(vector<int>& arr, int n){
        int ans = 0;
        int e = arr[0];
        for(int i= 1; i<n;i++){
            if(arr[i] < e){
                e = arr[i];
                ans = i;
            }
        }
        return ans;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        for(int i=0; i<k; i++){
            int mineleind = helper(nums,n);
            nums[mineleind] = multiplier * nums[mineleind];
        }
        return nums;
    }
};