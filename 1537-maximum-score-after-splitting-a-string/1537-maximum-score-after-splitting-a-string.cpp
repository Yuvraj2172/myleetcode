class Solution {
public:
    int maxScore(string s) {
        int ans =0 ;
        int z =0;
        int n = s.size();
        for(int i=0; i<n-1; i++){
            if(s[i] == '0'){
                z++;
            }
            int o =0;
            for(int j = i+1; j < n; j++){
                if(s[j] == '1'){
                    o++;
                }
            }

            ans = max(ans, z + o);
        }
        return ans;
    }
};