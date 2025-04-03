class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        n = len(nums)
        maxelesofar = 0
        ans = 0
        maxdiff = 0

        for num in nums:
            ans = max(ans, maxdiff * num)
            maxdiff = max(maxdiff, maxelesofar - num )
            maxelesofar = max(maxelesofar, num)
            

        return ans