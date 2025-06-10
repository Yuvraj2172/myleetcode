from collections import Counter
class Solution:
    def maxDifference(self, s: str) -> int:
        d = Counter(s)
        print(d)
        e, o = [],[]
        for c in d.values():
            if c % 2 == 0:
                e.append(c)
            else:
                o.append(c)
        e.sort()
        o.sort()

        return o[-1] - e[0]
       
    