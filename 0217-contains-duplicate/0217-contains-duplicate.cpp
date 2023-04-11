class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        int n = nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        return s.size()!=n;
    }
};