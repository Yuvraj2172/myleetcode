class Solution {
public:
    static bool cmp(int  a, int  b){
        string sa = to_string(a);
        string sb = to_string(b);

        if(sa + sb > sb + sa){
            return true;
        }
        return false;
    }
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(), cmp);
        if(nums[0] == 0)return "0";
        string ans = "";

        for(auto it : nums)ans += to_string(it);

        return ans;
    }
};