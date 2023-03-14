class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        while(i<nums.size()){
            if(nums[i]>=0){
                break;
            }
            i++;
        }
        int j = i-1;
        cout<<j<<" "<<i;
        vector<int> ans;
        while(i<=nums.size()-1 && j>=0){
            if(nums[i]*nums[i] <= nums[j]*nums[j]){
                ans.push_back(nums[i]*nums[i]);
                i++;
            }
            else{
                ans.push_back(nums[j]*nums[j]);
                j--;
            }
        }
        while(i<=nums.size()-1){
            ans.push_back(nums[i]*nums[i]);
            i++;
        }
         while(j>=0){
            ans.push_back(nums[j]*nums[j]);
            j--;
        }
        return ans;
    }
};