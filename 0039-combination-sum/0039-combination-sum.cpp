class Solution {
public:
    void helper(vector<int>& candidates, int n, vector<int>& temp , vector<vector<int>>& ans , int index, int target){
        if(index == n){
            if(target ==0){
                ans.push_back(temp);
                return;
            }
            return ;
        }
        if(candidates[index]<= target){
            temp.push_back(candidates[index]);
            helper(candidates, n , temp , ans , index, target - candidates[index]);
            temp.pop_back();
        }
        helper(candidates, n , temp, ans , index + 1, target );
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        int ind =0;
        vector<vector<int>> ans;
        int n = candidates.size();
        helper(candidates, n , temp , ans , ind, target);
        return ans;
    }
};