class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx=0, mn =0;
        int s =0;
        for(auto it : nums){
            s += it;
            mx = max(mx, s);
            mn = min(mn, s);
            if(mx < 0)mx = 0;
            if(mn > 0)mn = 0;
        }
        return mx - mn;
    }
};

