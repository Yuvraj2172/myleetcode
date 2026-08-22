class Solution:
    def checkDivisibility(self, n: int) -> bool:
        s = 0
        p = 1
        m = n

        while m :
            s += m % 10
            p *= m % 10
            m = m // 10
        if s + p == 0:
            return False
        return n % (s + p) == 0
