class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        p, m = 0, float('inf')
        for i in range(len(prices)):
            m = min(m, prices[i])
            p = max(p, prices[i] - m)
        return p