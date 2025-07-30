from itertools import groupby
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        maxi = max(nums)
        return max(sum(1 for item in group )for key, group in groupby(nums) if key == maxi)