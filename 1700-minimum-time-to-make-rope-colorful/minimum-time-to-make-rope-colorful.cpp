class Solution {
public:
    int minCost(string colors, vector<int>& arr) {
        int prev = 0;
        int ans =0;
        int n = arr.size();
        for(int i = 1; i<n;i++){
            if(colors[i] == colors[prev]){
                if(arr[i] < arr[prev]){
                    ans += arr[i];
                }else {
                    ans += arr[prev];
                    prev=i;
                }
            }else {
                prev = i;
            }
        }   
        return ans;
    }
};