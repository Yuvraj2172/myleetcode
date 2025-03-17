class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        mp = {}

        for i in nums:
            mp[i] = mp.get(i,0) + 1
        
        for values in mp.values():
            if values % 2 == 1:
                return False
        return True