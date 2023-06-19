class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int g=0;
        for(auto it: gain){
            g+=it;
            ans = max(ans , g);
        }
        return ans;
    }
};