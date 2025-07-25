class Solution:
    def maxSum(self, nums: List[int]) -> int:
        max_ele = max(nums)

        return max_ele if max_ele < 0 else sum([i for i in set(nums) if i > 0])