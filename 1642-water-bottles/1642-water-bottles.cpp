class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;

        while(numBottles >= numExchange){
            int nb = numBottles / numExchange;
            int remaining = numBottles % numExchange;
            ans += nb;
            numBottles = nb + remaining;

        }
        return ans;
    }
};