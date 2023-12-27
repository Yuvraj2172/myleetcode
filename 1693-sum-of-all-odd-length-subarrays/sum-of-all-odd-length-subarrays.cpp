class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size(), ans =0;
        for(int i=0; i<n;i++){
            for(int j = i; j<n; j+=2){
                for(int k = i; k<=j;k++){
                    ans += arr[k];
                }
            }
        }
        return ans;
    }
};