class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long  ans =0, count =0;
        int n = nums.size();
        for(int i=0; i<n;i++){
            while(i<n && nums[i]==0){
                count++;
                i+=1;
            }
            ans += ((count)*(count+1)/2);
            count=0;
        }
        return ans;
    }
};