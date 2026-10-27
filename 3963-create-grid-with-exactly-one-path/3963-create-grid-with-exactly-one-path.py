class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        ans = [["#"] * n for i in range(m)]

        for j in range(n):
            ans[m-1][j] = '.'
        for i in range(m):
            ans[i][0] = '.'
        return [''.join(row) for row in ans]