class Solution {
public:
    int minSwaps(string s) {
        int ans =0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '[')ans+=1;
            else {
                if(ans > 0){
                    ans -= 1;
                }else {
                    ans += 1;
                }
            }
        }
        return (ans + 1)/2;
    }
};