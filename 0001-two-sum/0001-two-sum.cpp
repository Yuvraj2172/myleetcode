class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int cmp = target - nums[i];
            if(mp.find(cmp)!=mp.end()){
                return {mp[cmp], i};
            }
            else {
                mp[nums[i]] =i;
            }
        }
        return res;
    }
};