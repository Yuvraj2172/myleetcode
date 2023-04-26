class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        priority_queue<int> pq;
        for(auto it : mp){
            pq.push(it.second);
        }
        vector<int> ans;
        while(k>0){
            int topElement = pq.top();
            pq.pop();
            for(auto it : mp){
                if(it.second == topElement){
                    ans.push_back(it.first);
                    mp.erase(it.first);
                    k--;
                    break;
                }
            }
        }
        return ans;
    }
};