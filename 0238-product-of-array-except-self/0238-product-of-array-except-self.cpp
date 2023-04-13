class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int n = nums.size();
        vector<int> lp(n), rp(n), ans(n);
        int p =1;
        lp[0]=1;
        for(int i=1;i<n;i++){
            lp[i]=p*nums[i-1];
            p = lp[i];
        }
        // for(auto it : lp)cout<<it<<" ";
        // cout<<"\n";
        p=1;
        rp[n-1]=1;
        for(int i = n-2;i>=0;i--){
            rp[i] = p*nums[i+1];
            p= rp[i];
        }
        // for(auto it : rp)cout<<it<<" ";
        // cout<<"\n";
        for(int i=0;i<n;i++){
            ans[i] = lp[i]*rp[i];
        }
        return ans;
    }
};