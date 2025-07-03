class Solution:
    def kthCharacter(self, k: int) -> str:
        s = 'a'
        while len(s) < k:
            n = len(s)
            for i in range(n):
                s+= chr(ord(s[i]) + 1)
        return s[k-1]