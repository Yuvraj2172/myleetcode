class Solution {
public:
    static bool sortsecond(vector<int>& a, vector<int>& b){
        return b[1] > a[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), sortsecond);
        int ans =1;
        int prev= pairs[0][1];
        for(int i=1 ; i<pairs.size();i++){
            if(pairs[i][0] > prev){
                ans++;
                prev = pairs[i][1];
            }
        }
        return ans;
    }
};