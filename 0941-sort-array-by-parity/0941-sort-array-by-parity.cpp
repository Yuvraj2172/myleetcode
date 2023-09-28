class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> e,o;
        for(auto it : nums){
            if(it&1)o.push_back(it);
            else e.push_back(it);
        }
        vector<int> ans;
        for(auto it : e)ans.push_back(it);
        for(auto it : o)ans.push_back(it);
        return ans;
    }
};