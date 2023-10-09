class Solution {
public:
    void helper(int index, vector<int> temp, vector<int>& nums, set<vector<int>>& s){
        if(index == nums.size()){
            s.insert(temp);
            return;
        }
        for(int i= index; i< temp.size(); i++){
            swap(temp[i], temp[index]);
            helper(index +1, temp, nums ,s);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> op;
        vector<int> temp = nums;
        set<vector<int>> s;
        helper(0 , temp , nums, s);
        for(auto it : s)op.push_back(it);
        return op;
    }
};