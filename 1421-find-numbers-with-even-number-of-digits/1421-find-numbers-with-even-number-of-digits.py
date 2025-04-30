class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        ans = 0
        for n in nums:
            c =0 
            while n != 0:
                n //= 10
                c += 1
            if c % 2 == 0:
                ans += 1
        
        return ans