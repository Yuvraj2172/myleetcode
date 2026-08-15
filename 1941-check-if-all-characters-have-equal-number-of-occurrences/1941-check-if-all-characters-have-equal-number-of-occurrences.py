class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        mp = Counter(s)
        t = mp[s[0]]
        for key, value in mp.items():
            if t != value:
                return False
        return True