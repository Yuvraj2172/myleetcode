class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        int n = nums.size();
        vector<int> helper(n+1,-1);
        for(auto it : nums){
            helper[it] += 1;
        }
        for(int i=1; i<n+1; i++){
            if(helper[i] == -1)ans[1] = i;
            if(helper[i] == 1)ans[0] =i ;
        }
        return ans;
    }
};