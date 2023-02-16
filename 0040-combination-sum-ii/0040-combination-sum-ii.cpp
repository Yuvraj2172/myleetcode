class Solution {
public:
    void helper(vector<int>& arr, int target , vector<vector<int>>& ans , vector<int>& temp , int index){
        if(target ==0){
            ans.push_back(temp);
            return;
        }
        for(int i= index ; i<arr.size();i++){
            if(i > index && arr[i] == arr[i-1])continue;
            if(arr[i] > target )break;
            temp.push_back(arr[i]);
            helper(arr, target- arr[i] , ans , temp , i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(candidates , target , ans , temp , 0);
        return ans;
    }
};