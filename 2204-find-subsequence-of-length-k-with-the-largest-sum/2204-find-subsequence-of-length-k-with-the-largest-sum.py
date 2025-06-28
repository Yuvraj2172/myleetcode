class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        arr = [(val, index) for index, val in enumerate(nums)]
        
        arr.sort(key = lambda x : -x[0])

        arr = arr[:k]

        arr.sort(key = lambda x : x[1])

        return [val for val, _ in arr] 