class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        mp = Counter(answers)
        ans = 0
        for r in mp:
            ans += ceil(float(mp[r])/ (r + 1))* (r + 1)
        return int(ans)

