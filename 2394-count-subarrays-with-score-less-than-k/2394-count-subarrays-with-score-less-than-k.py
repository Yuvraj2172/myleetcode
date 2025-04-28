class Solution(object):
    def countSubarrays(self, nums, k):
        count = 0
        for right in range(len(nums)):
            sum = 0
            for left in range(right, len(nums)):
                sum += nums[left]
                if sum * (left - right + 1) < k:
                    count += 1
        return count