static const int _ = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> helper(vector<int>& nums, int n){
        map<int,int> mp;
        for(auto it : nums)mp[it]++;
        nums.clear();
        for(auto it : mp){
            while(it.second--){
                nums.push_back(it.first);
            }
        }
        return nums;
    }
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<2)return 0;
        vector<int> arr = helper(nums,n);
        int ans = INT_MIN;
        for(int i=1; i<n;i++){
            ans = max(ans, arr[i] - arr[i-1]);
        }
        return ans;
    }
};