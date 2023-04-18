class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n  =nums.size();
        int uvreachable = 0;
        for(int i=0;i<n;i++){
            if( uvreachable < i)return false;
            uvreachable = max(uvreachable , i + nums[i]);
        }
        return true;
    }
};