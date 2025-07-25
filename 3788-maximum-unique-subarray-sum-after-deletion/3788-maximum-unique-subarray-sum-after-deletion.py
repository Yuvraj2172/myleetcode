class Solution:
    def maxSum(self, nums: List[int]) -> int:
        return max(nums) if max(nums) < 0 else sum([i for i in set(nums) if i > 0])