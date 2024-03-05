class Solution {
public:
    void sortColors(vector<int>& nums) {
        int o(0), z(0), t(0);
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1)o++;
            else if(nums[i] ==0)z++;
            else t++;
        }
        int i = 0;
        while(z--){
            nums[i++] = 0;
        }
        while(o--){
            nums[i++] = 1;
        }
        while(t--){
            nums[i++] = 2;
        }
    }
};