class Solution {
public:
    void helper(int ind, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans, map<int,int>& freq){
        if(ind == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(freq.find(nums[i]) == freq.end()){
                freq[nums[i]]=1;
                temp.push_back(nums[i]);
                helper(ind+1 , temp , nums, ans , freq);
                freq.erase(nums[i]);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        map<int,int> freq;
        helper(0 , temp , nums, ans , freq);
        return ans;
    }
};