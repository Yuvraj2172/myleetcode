class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int ans = -(1e9+7);
        int n = arr.size();
        
        int maxi = arr[0].back();
        int mini = arr[0][0];
        int maxD = 0;
        for(int i =1; i<n;i++){
            maxD = max(maxD, abs(maxi - arr[i][0]));
            maxD = max(maxD, abs(mini - arr[i].back()));

            maxi = max(maxi, arr[i].back());
            mini = min(mini, arr[i][0]);
        }

        return maxD;
        
    }
};