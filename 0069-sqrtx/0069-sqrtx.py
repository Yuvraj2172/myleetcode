class Solution:
    def mySqrt(self, x: int) -> int:
        if x ==0 :
            return 0
        ans = 1
        low,high = 1, x
        while low <= high:
            mid = (low + high) // 2
            if mid * mid <= x:
                ans = mid
                low += 1
            else:
                high = mid - 1
        return ans