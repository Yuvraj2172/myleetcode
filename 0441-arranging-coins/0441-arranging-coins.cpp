class Solution {
public:
    int arrangeCoins(int n) {
        int coins=0;
        while(n>coins){
            coins +=1;
            n-=coins;
        }
        return coins;
    }
};