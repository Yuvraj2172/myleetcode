class Solution {
public:

    void helper(int curr, int n, vector<int>& ans){
        if(curr > n)return;
        ans.push_back(curr);
        for(int i=0; i<=9; i++){
            if(curr * 10 + i > n)return;
            helper(curr * 10 + i, n, ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1; i<=9;i++){
            helper(i,n,ans);
        }
        return ans;
    }
};