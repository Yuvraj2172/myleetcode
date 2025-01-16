class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        n, m = len(nums1), len(nums2)

        a, b = 0,0

        if n %2 !=0:
            for i in nums2:
                a ^= i

        if m % 2 !=0:
            for i in nums1:
                b ^= i

        return a ^ b