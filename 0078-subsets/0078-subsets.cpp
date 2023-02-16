class Solution {
public:
    void helper(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int index){
        if(index == nums.size()){
        ans.push_back(temp);
        return;
        }
        temp.push_back(nums[index]);
        helper(nums, temp , ans , index+1);
        temp.pop_back();
        helper(nums , temp , ans , index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(nums, temp, ans, 0);
        return ans;
    }
};