class Solution:
    def kthSmallestProduct(self, nums1: List[int], nums2: List[int], k: int) -> int:
        n = len(nums1)
        m = len(nums2)
        # 0's cannot be divided
        nonzero_nums1 = []
        cnt_0 = 0
        for x in nums1:
            if x == 0:
                cnt_0 += 1
            else:
                nonzero_nums1.append(x)
        
        # Find the Minimum and Maximum products
        low = -10**10
        high = 10**10

        nums1.clear()
        nums1 = nonzero_nums1

        # If the divisor is negative, take the right part otherwise left
        def required_numbers(mid, val, nums2):
            if val < 0:
                return len(nums2) - bisect.bisect_left(nums2, mid / val)
            return bisect.bisect_right(nums2, mid / val)
        
        ans = -1

        while low <= high:
            mid = low + (high-low)//2

            nums_lt_mid = ((cnt_0 * m) if mid >= 0 else 0)
            
            for i in range(len(nums1)):
                nums_lt_mid += required_numbers(mid, nums1[i], nums2)
                
            if nums_lt_mid >= k:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1

        return ans
