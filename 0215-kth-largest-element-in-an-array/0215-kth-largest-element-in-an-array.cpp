class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n= nums.size();
        for(auto it : nums)pq.push(it);
        while(k-1){
            pq.pop();
            k--;
        }
        return pq.top();
   }
};