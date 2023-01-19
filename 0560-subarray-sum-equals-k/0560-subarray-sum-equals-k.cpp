class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = (int)arr.size();
        int ans =0;
        unordered_map<int,int> mp;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
             if(sum==k){
                ans++;
            }
            if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }

            mp[sum] ++;            
        }
        return ans;
    }
};