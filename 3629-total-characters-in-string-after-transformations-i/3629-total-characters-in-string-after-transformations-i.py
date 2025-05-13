class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        f = [0] * 26
        MOD = 1e9 + 7
        for c in s:
            f[ord(c) - ord('a')] += 1
        
        for _ in range(t):
            nf = [0] * 26
            for i in range(26):
                nf[(i + 1) % 26] += f[i]
                if i == 25:
                    nf[1] += f[i]
                    nf[1] %= MOD
            f = nf
        return int(sum(f) % MOD)