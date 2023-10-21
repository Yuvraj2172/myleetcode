class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans =0;
        for(int i=0; i<nums.size();i++){
            int t=0;
            while(nums[i]!=0){
                int l = nums[i]%10;
                t++;
                nums[i] = nums[i]/10;
            }
            if(t%2==0)ans++;
        }
        return ans;
    }
};