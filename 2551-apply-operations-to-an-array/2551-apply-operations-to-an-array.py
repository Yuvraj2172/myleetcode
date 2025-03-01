class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        for i in range(len(nums) - 1):
            if nums[i] == nums[i+1]:
                nums[i] = nums[i] * 2
                nums[i+1] = 0
        
        a,b = [],[]
        for i in range(len(nums)):
            if nums[i] == 0:
                a.append(nums[i])
            else:
                b.append(nums[i])
        
        res= []

        for i in b:
            res.append(i)
        for i in a:
            res.append(i)

        return res