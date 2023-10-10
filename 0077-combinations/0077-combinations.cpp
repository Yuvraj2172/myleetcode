class Solution {
public:
    void helper(int n , int k, int s, vector<vector<int>>& ans , vector<int>& temp){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        for(int i = s; i<=n;i++){
            temp.push_back(i);
            helper(n, k-1, i+1, ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(n, k, 1, ans, temp);
        return ans;
    }
};