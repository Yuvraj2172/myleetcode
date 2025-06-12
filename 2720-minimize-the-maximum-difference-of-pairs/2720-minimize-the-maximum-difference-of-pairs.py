class Solution:
    def is_valid(self,threshold, p, nums):
        cnt = 0
        i =0 
        while i < len(nums) - 1:
            if abs(nums[i] - nums[i+1]) <= threshold:
                cnt += 1
                i += 2
            else:
                i +=1
            if cnt == p:
                return True
        return False

    def minimizeMax(self, nums: List[int], p: int) -> int:
        if p == 0:
            return 0
        nums.sort()
        res = 10 ** 9
        left, right = 0, 10**9

        while left <= right:
            m = left + (right - left) // 2
            if self.is_valid(m,p,nums):
                res = m
                right = m - 1
            else:
                left = m + 1
        return res