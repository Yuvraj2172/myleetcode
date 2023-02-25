class Solution {
    public int maxProfit(int[] prices) {
        int buy=Integer.MAX_VALUE;
        int maxProfit=0;
        for(int i=0;i<prices.length;i++){
            if(buy>prices[i]){
                buy = prices[i];
            }
            maxProfit = Math.max(prices[i]-buy,maxProfit);
        }
        return maxProfit;
    }
}