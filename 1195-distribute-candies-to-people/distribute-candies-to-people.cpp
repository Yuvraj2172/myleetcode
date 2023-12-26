class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> ans(n,0);
        int i=0, c=1;
        while(candies>0){
            if(i>=n && candies!=0){
                i=0;
            }

                if(candies < c){
                    ans[i]+=candies;
                    return ans;
                }
                else {
                    ans[i] += c;
                    candies -= c;
                }
            
            i++; c++;
        }
        return ans;
    }
};

