class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        last = [-1] * 32
        for i in range(len(nums) - 1, -1, -1):
            for b in range(32):
                if nums[i] & (1 << b):
                    last[b] = i
            nums[i] = max(1, max(last) - i + 1)
        return nums