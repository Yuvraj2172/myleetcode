class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int li =1, ld = 1;
        int n = arr.size();
        int ans = 1;
        for(int i = 1; i < n; i++){
            if(arr[i] < arr[i-1]){
                li++;
                ans = max(ans, li);
                ld = 1;

            }else if(arr[i] > arr[i-1]){
                ld++;
                ans = max(ans, ld);
                li = 1;
            }else{
                li = 1;
                ld = 1;
            }
        }
        return ans;
    }
};