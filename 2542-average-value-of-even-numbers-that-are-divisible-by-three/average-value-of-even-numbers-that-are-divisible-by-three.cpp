class Solution {
public:
    int averageValue(vector<int>& nums) {
        int ans =0, c =0;
        for(auto it : nums){
            if(it%6==0){
                ans += it;
                c++;
            }
        }
        return  (c==0) ? 0 :  ans/c;
    }
};