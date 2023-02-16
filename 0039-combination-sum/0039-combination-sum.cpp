class Solution {
public:
    void helper(vector<int> arr, int target , vector<vector<int>>& ans , vector<int>& temp , int ind){
        if(ind == arr.size()){
            if(target==0){
                ans.push_back(temp);
                return;
            }
             return;
        }
        if(arr[ind] <= target){
            temp.push_back(arr[ind]);
            helper(arr , target - arr[ind], ans , temp , ind);
            temp.pop_back();
        }
        helper(arr, target , ans , temp, ind+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(candidates, target , ans , temp, 0);
        return ans;
    }
};