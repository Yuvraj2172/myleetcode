class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> mp(32,-2);
        mp[0] = -1;
        int ans =0;
        int mask = 0;

        int n = s.size();
        for(int i=0; i<n;i++){
            int ch = s[i];

            if(ch == 'a'){
                mask ^= 1;
            }else if(ch == 'e'){
                mask ^=2;
            }else if(ch == 'i'){
                mask ^=4;
            }else if(ch == 'o'){
                mask ^=8;
            }else if(ch == 'u'){
                mask ^=16;
            }

            int prev = mp[mask];
            if(prev == -2){
                mp[mask] = i;
            }else {
                ans = max(ans, i - prev);
            }
        }
        
        return ans;
    }
};