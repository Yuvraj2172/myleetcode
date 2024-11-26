class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        bitset<100> bs;

        for(const auto&  it : edges){
            bs.set(it[1]);
        }
        int ans = -1;

        for(int i=0; i<n; i++){
            if(!bs[i]){
                if(ans != -1){
                    return -1;
                }

                ans = i;
            }
        }
        return ans;
    }
};