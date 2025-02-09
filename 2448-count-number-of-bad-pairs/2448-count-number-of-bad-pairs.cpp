class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        long long n = nums.size();
        long long good_pairs = 0;
        for(int i = 0; i < n; i++){
            int key = nums[i] - i;
            good_pairs += mp[key];
            mp[key]++;
        }
        return (n * (n - 1)) / 2 - good_pairs;
    }
};

