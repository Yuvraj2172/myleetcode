class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()
        ans = []
        for i in range(0, len(nums), 3):
            temp = []
            if abs(nums[i] - nums[i+1]) <= k and abs(nums[i+1] - nums[i+2]) <= k and abs(nums[i] - nums[i+2]) <= k:
                temp.append(nums[i])
                temp.append(nums[i+1])
                temp.append(nums[i+2])
                ans.append(temp)
            else:
                return []
        return ans
            