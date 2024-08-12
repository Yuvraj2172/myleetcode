class KthLargest {
public:
    int gk;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        gk = k;
        for(auto it : nums){
            if(pq.size() < gk)pq.push(it);
            else if(pq.size() == gk && it >= pq.top())pq.push(it);
            if(pq.size() > k)pq.pop();
        }
    
    }
    
    int add(int val) {
         if(pq.size() < gk)pq.push(val);
            else if(pq.size() == gk && val >= pq.top())pq.push(val);
        if(pq.size() > gk)pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */