class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;
        for(int i=0; i<n;i++){
            arr.push_back(nums[i]); 
        }
        vector<int> ans;
    // for(auto it : arr)cout<< it <<" ";
        for(int i=0;i<n;i++){
            int flag = 0;
            for(int j = i+1; j<arr.size();j++){
                if(arr[j] > arr[i]){
                    ans.push_back(arr[j]);
                    flag = 1;
                    break;
                }
            }
            if(!flag)ans.push_back(-1);
        }
        return ans;
    }
};