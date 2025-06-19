class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        i,j,n = 0,0, len(nums)
        c =0
        while j < n:
            if nums[j] - nums[i]<=k:
                j+=1
            else:
                c +=1
                i = j
        return c + 1