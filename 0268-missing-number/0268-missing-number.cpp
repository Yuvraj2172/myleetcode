class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> res(nums.size()+1,-1);
        for(int i=0;i<nums.size();i++){
            res[nums[i]] = 1;
        }
        for(int i=0;i<res.size();i++){
            if(res[i]==-1)return i;
        }
        return 1;
    }
};