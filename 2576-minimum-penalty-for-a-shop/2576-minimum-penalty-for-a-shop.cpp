class Solution {
public:
    int bestClosingTime(string s) {
        int p = count(s.begin(), s.end(), 'Y'),minp = 0, cp =0,ans =0, n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='Y')cp--;
            else cp++;
            if(cp < minp){
                ans = i+1;
                minp = cp;
            }
        }
        return ans;
    }
};