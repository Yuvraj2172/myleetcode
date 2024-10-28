class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        num_set = set(nums)

        ans = 0

        for n in nums:
            temp = n
            res = 0
            
            while temp in num_set:
                res += 1
                temp = temp * temp

            if temp >= 2:
                ans=  max(res, ans)
            
        return ans if ans >= 2 else -1