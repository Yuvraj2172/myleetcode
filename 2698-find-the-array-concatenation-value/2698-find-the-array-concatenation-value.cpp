class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans =0;
        long long mod = 1e9+7;
        int start =0, end = nums.size()-1;
        if(nums.size()%2==0){
            while(start < end){
            string a = to_string(nums[start]);
            string b = to_string(nums[end]);
            a+=b;
            ans +=stoi(a);
            start ++;
            end--;
            
        }
        return ans;
        }
        else {
            while(start < end){
            string a = to_string(nums[start]);
            string b = to_string(nums[end]);
            a+=b;
            ans +=stoi(a);
            start ++;
            end--;
            
        }
        ans += nums[start];
        return ans;
        }
        
    }
};