class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        ans = [["#"] * n for i in range(m)]

        for j in range(n):
            ans[0][j] = '.'
        for i in range(m):
            ans[i][n-1] = '.'
        print(ans)
        return [''.join(row) for row in ans]