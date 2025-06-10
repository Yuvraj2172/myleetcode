from collections import Counter
class Solution:
    def maxDifference(self, s: str) -> int:
        mp = [0] * 26
        for c in s:
            mp[ord(c) - ord('a')] +=1

        maxi, mini = 0, len(s)
        for i in range(26):
            if mp[i] % 2 == 0 and mp[i] > 0:
                mini = min(mini, mp[i])
            else:
                maxi = max(maxi, mp[i])
        return maxi - mini