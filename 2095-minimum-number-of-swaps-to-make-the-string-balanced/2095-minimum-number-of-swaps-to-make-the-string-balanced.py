class Solution:
    def minSwaps(self, s: str) -> int:
        ans = 0

        for i in range(len(s)):
            if s[i] == '[':
                ans += 1
            else:
                if ans > 0:
                    ans -= 1
                else: ans +=1

        return (ans + 1)//2    