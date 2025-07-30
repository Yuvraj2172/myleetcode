class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        maxi = max(nums)
        temp,ans = 0,0
        for i,ele in enumerate(nums):
            temp = temp + 1 if ele == maxi else 0
            ans = max(ans, temp)
        return ans