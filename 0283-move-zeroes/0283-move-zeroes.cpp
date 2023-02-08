class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        queue<int> q;
        int numzeroes =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)numzeroes++;
            if(nums[i]!=0)q.push(nums[i]);
        }
        nums.clear();
        while(!q.empty()){
        nums.push_back(q.front());
            q.pop();
        }
        while(numzeroes!=0){
        nums.push_back(0);
            numzeroes--;
        }
    }
};