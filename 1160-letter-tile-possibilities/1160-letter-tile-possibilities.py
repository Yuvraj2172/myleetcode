class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        freq_map = Counter(tiles)

        def dfs(i):
            s = 1
            for k, v in freq_map.items():
                if v == 0:
                    continue
                
                freq_map[k] -= 1
                s += dfs(i + 1)
                freq_map[k] += 1
            
            return s
        
        return dfs(0) - 1