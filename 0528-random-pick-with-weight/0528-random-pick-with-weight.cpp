class Solution {
public:
    vector<int> weights;
    int size;
    int sum =0;
    Solution(vector<int>& w) {
        size = w.size();
        for(auto &it : w){
            sum+= it;
            weights.push_back(sum);
        }
    }
    
    int pickIndex() {
        int index = rand()% sum;
        auto it  = upper_bound(weights.begin(), weights.end() , index) - weights.begin();
        return it;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */