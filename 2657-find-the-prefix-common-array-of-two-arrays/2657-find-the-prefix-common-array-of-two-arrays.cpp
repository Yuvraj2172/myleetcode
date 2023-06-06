class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> helper(A.size()+1,0);
        vector<int> ans(A.size(),0);
        int n = A.size();
        int count =0;
        for(int i=0; i< n;i++){
            if(++helper[A[i]]==2)count++;
            if(++helper[B[i]]==2)count++;
            ans[i] = count;
        }
        return ans;
    }
};