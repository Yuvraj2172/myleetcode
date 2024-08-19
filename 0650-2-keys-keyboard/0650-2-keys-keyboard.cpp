class Solution {
public:
    int minSteps(int n) {
        int ans  =0 ;
        int fac = 2;
        while(n >1){
            while(n % fac == 0){
            ans += fac;
            n/=fac;
            }
            fac++;
        }
        return ans;
    }
};