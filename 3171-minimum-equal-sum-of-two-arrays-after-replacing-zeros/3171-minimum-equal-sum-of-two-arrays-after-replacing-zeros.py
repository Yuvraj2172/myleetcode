class Solution:
    def minSum(self, a: List[int], b: List[int]) -> int:
        z1, z2, s1,s2 = a.count(0), b.count(0), sum(a), sum(b)

        min1 = s1 + z1
        min2 = s2 + z2 

        if z1 == z2 and z2 == 0:
            return s1 if s1 == s2 else -1
        elif z1 == 0:
            return min1 if min2 <= s1 else -1
        elif z2 ==0 :
            return min2 if min1 <= s2 else -1
        return max(min1, min2)