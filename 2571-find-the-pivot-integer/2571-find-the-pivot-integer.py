class Solution:
    def pivotInteger(self, n: int) -> int:
        ts = (n * (n + 1)) // 2
        for i in range(1,n + 1 ):
            s = (i * (i + 1)) // 2
            if s == ts - s + i:
                return i
        return -1