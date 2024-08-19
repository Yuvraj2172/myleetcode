class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)return 1;
        vector<long> dp(n,0);
        dp[0] = 1;

        long fac2 = 2, fac3 = 3, fac5 = 5;
        long ind2 = 0, ind3 = 0, ind5 = 0;

        for(int i=1; i<n;i++){
            long  nn = min(fac2, min(fac3 , fac5));
            dp[i] = nn;
            // cout<<nn<<" ";
            if(nn == fac2 ){ind2++;
            cout<<ind2;
            fac2=  2 * dp[ind2];}
            if(nn == fac3){
                ++ind3;
                fac3 = 3 * dp[ind3];}
            if(nn == fac5){
                ind5++;
                fac5 = 5 * dp[ind5];}
        }
        return dp[n-1];
    }
};