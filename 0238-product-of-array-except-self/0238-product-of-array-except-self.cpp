class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> leftproduct(n);
        vector<int> rightproduct(n);
        int prod =1;
        leftproduct[0]=1;
        for(int i=1;i<n;i++){
            leftproduct[i] = leftproduct[i-1]* nums[i-1];
            prod = leftproduct[i];
        }
        
        prod =1;
        rightproduct[n-1]=1;
        for(int i=n-2;i>=0;i--){
            rightproduct[i] = prod*nums[i+1];
            prod = rightproduct[i];
        }
        for(int i=0;i<n;i++){
            ans[i] = leftproduct[i] * rightproduct[i];
        }
        return ans;
    }
};