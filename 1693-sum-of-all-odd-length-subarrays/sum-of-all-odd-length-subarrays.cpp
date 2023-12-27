class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size(), ans =0;
        for(int i=0 ;i<n;i++){
            ans += (((i+1)*(n-i)+1)/2)*arr[i];
        }
        return ans;
    }
};