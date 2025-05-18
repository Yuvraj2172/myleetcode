class Solution:
    def colorTheGrid(self, R: int, C: int) -> int:
        MOD = 10 ** 9 + 7
        @cache
        def count(mask, x,y):
            if x == R:
                return count(mask, 0, y + 1)
            if y == C:
                return 1
            total = 0

            if x - 1 >=0:
                color_above = (mask % 3)
            else:
                color_above = -1
            
            if y-1 >=0:
                color_left = mask // (3 ** (R -1))
            else:
                color_left = -1
            
            for c in range(3):
                if c != color_above and c != color_left:
                    new_mask = (mask * 3 + c) % (3 ** R)
                    total += count(new_mask, x +1, y)
            return total % MOD
        return count(0,0,0) % MOD