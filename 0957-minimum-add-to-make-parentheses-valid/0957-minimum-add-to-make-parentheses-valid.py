class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        o,cl = 0,0

        for c in s:
            if c == '(':
                o+=1
            else:
                if o > 0:
                    o -=1
                else:
                    cl += 1
        return o + cl
        