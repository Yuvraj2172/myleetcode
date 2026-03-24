class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        row, col = len(grid), len(grid[0])
        res = [[0] * col for _ in range(row)]
        MOD = 12345
        
        # Backward: suffix products
        suf = 1
        for i in range(row - 1, -1, -1):
            for j in range(col - 1, -1, -1):
                res[i][j] = suf
                suf = (suf * grid[i][j]) % MOD
        
        # Forward: multiply by prefix
        pre = 1
        for i in range(row):
            for j in range(col):
                res[i][j] = (res[i][j] * pre) % MOD
                pre = (pre * grid[i][j]) % MOD
        
        return res