class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        min_val = nums[0]
        ans = -1
        for i in range(len(nums)):
            if nums[i] > min_val:
                ans = max(ans, nums[i] - min_val)
            else:
                min_val = nums[i]
        return ans