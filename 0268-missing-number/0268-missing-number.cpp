class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> res(nums.size()+1,-1);
        int ans=0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if((nums[i]^i)!=0){
                ans = i;
                break;
            }
        }
        if(nums[nums.size()-1]!=nums.size())return nums.size();
        return ans;
        // return 1;
    }
};