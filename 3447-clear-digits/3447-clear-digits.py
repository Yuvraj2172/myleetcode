class Solution:
    def clearDigits(self, s: str) -> str:
        s = list(s)
        j =0 
        for i , c in enumerate(s):
            if c.isdigit() and j > 0 :
                j-=1
            else:
                s[j] = c
                j += 1

        s = s[:j]
        return "".join(s)

