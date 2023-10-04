class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans =0;
        for(auto it : mp){
            int n = it.second;
            ans += ((n)*(n-1)/2);
        }
        return ans;
    }
};