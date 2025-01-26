class Solution {
public:
    int maxAdjacentDistance(vector<int>& arr) {
        int n = arr.size();
        arr.push_back(arr[0]);
        int ans = INT_MIN;
        for(int i =0 ; i < n; i++){
            ans = max(ans, abs(arr[i] - arr[i+1]));
        }
        return ans;
    }
};