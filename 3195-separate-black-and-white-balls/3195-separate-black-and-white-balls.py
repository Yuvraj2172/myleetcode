class Solution:
    def minimumSteps(self, s: str) -> int:
        ans = 0
        c = 0

        for i in range(len(s)):
            if s[i] == '1':
                c += 1
            else: ans += c
        return ans