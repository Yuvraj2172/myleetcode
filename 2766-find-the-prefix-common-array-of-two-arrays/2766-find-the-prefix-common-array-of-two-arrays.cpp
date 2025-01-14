class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> helper(n + 1, 0);
        vector<int> ans(n,0);
        int c =0;
        for(int i=0; i<n;i++){
            if(++helper[A[i]] == 2)c += 1;
            if(++helper[B[i]] == 2)c += 1;
            ans[i] = c;
        }
        return ans;
    }
};