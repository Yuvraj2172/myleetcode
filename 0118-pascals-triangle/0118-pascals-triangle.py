class Solution:
    def generate(self, n: int) -> List[List[int]]:
        ans = []
        for i in range(n):
            t = [1] * (i + 1 )
            for j in range(i):
                if j == 0 or j == i + 1:
                    continue
                else:
                    t[j] = ans[i-1][j-1] + ans[i-1][j]
            ans.append(t)
        return ans