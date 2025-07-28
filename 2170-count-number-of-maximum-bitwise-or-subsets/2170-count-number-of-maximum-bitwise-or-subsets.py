from functools import reduce
class Solution:
    def subsets(self, nums, ind, curr_or, max_or):
        if ind == len(nums):
            return 1 if curr_or == max_or else 0
        take = self.subsets(nums, ind + 1, curr_or | nums[ind], max_or)
        non_take = self.subsets(nums, ind+1, curr_or, max_or)
        return sum([take,non_take])
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        curr_or = reduce(lambda x,y : x | y, nums)
        return self.subsets(nums, 0, 0, curr_or)