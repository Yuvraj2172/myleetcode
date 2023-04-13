class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            int slow = i+1, fast = nums.size()-1;
            while(slow < fast){
                int sum = nums[i]+ nums[slow] + nums[fast];
                if(sum > 0 )fast--;
                else if(sum<0) slow++;
                else {
                    // vector<int> temp = {nums[i] , nums[slow] , nums[fast]};
                    // ans.push_back(temp);
                    s.insert({nums[i] , nums[slow] , nums[fast]});
                    slow++;
                    fast--;
                }
            }
        }
        for(auto it : s)ans.push_back(it);
        return ans;
    }
};