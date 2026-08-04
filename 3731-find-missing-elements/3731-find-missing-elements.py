class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        start = min(nums)
        end = max(nums)

        return [ele for ele in range(start, end + 1) if ele not in nums]
        