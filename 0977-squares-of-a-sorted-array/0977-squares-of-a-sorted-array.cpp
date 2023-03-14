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
        while(i<=nums.size()-1 || j>=0){
            int val1=1e9,val2=1e9;
            if(i<nums.size())
                val1 = nums[i]*nums[i];
            if(j>=0)
                val2 = nums[j]*nums[j];
            if(val1<val2)
            {
                ans.push_back(val1);
            i++;
            }
            else
            {
                ans.push_back(val2);
            j--;
            }
                
        }
        
        return ans;
    }
};