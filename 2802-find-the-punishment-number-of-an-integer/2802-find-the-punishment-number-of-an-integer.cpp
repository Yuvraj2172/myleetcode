class Solution {
public:
    int helper(int sq, int n){
        if(sq == n)return 1;
        if(sq < n || n <0)return 0;
        return (helper(sq / 10, n - sq % 10) || 
                helper(sq / 100, n - sq % 100) || 
                helper(sq / 1000, n - sq % 1000));
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=0; i <= n; i++){
            int sq = i * i;
            if(helper(sq, i))ans+=sq;
        }
        return ans;
    }
};