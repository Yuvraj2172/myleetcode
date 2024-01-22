

// int maximumGap(vector<int> &nums)
// {
//     int n = nums.size();
//     if (n < 2)
//         return 0;
//     vector<int> sortednums = countsort(nums);

//     int maxgap = INT_MIN;
//     for (int i = 1; i < n; i++)
//     {
//         int currgap = sortednums[i] - sortednums[i - 1];
//         maxgap = max(maxgap, currgap);
//     }

//     return maxgap;
// }

class Solution {
public:

   vector<int> helper(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> m;
    for (int i = 0; i < n; i++ )
        m[nums[i]]++;

    nums.clear();
    for (auto it : m)
    {
        int cnt = it.second;
        while (cnt--)
        {
            nums.push_back(it.first);
        }
    }
    return nums;
}
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2)return 0;
        int n = nums.size();
        
        vector<int> nigga = helper(nums);
        int diff = INT_MIN;
        for(int i=1; i<n;i++){
            diff = max(diff, nums[i] - nums[i-1]);
        }
        return diff;
    }
};