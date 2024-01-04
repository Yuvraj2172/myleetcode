class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res =0;
        int i =0;
        int n = nums.size();
        while(i<n){
            int c =0;
            int t = i;
            while(t < n && nums[t] == nums[i]){
                t+=1;
            }
            c = t -  i;
            if(c==1)return -1;
            res += c/3;
            if(c%3)res++;
            i = t;
        }
        return res;
    }
};