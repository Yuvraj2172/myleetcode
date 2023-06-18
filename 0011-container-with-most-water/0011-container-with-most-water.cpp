class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans =0;
         int slow =0;
        int fast = height.size()-1;
        while(slow < fast){
            ans = max(ans , (fast - slow)* min(height[slow] , height[fast]) );
            if(height[slow] < height[fast])slow++;
            else fast--;
        }
        return ans;
    }
};