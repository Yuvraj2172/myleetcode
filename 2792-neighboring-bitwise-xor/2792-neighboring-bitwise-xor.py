class Solution:
    def doesValidArrayExist(self, arr: List[int]) -> bool:
        x = 0
        for i in arr:
            x ^= i
        return True if x == 0 else False