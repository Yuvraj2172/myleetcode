class Solution {
public:
    int findMinDifference(vector<string>& tp) {
        int n = tp.size();
        vector<int> arr(n,0);
        for(int i=0; i<n;i++){
            string hr = tp[i].substr(0,2);
            string min = tp[i].substr(3,2);
            int t = stoi(hr)*60 + stoi(min);
            arr[i] = t; 
        }
        

        sort(arr.begin(), arr.end());
        // for(auto it: arr)cout<<it<<"\n";
        int ans = INT_MAX;
        for(int i=0 ;i<n-1;i++){
            int diff = arr[i+1] - arr[i];
            cout<<diff<<" ";
            ans = min(ans, diff);
        }

        int cd = 1440 - arr.back() + arr[0];
        ans = min(ans, cd);

        return ans;
    }
};