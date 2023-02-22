class Solution {
public:
    bool isPossible(vector<int>& weights , int mid , int days){
        int d= 1;
        int sum=0;
        for(auto it : weights){
            sum+=it;
            if(sum>mid){
                d++;
                sum = it;
            }
        }
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low =0, high =0;
        for(auto it : weights){
            low = max(low, it);
            high += it;
        }
        if(weights.size() == days )return low;
        int ans ;
        while(low<= high){
            int mid = low + ( high - low)/2;
            if(isPossible(weights , mid , days)){
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};