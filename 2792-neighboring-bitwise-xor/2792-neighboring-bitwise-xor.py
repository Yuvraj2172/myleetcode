class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        x = 0
        for i in derived:
            x ^= i
        
        return True if x == 0 else False