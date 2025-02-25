class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        curr_sum,even,odd,res = 0,0,0,0

        for i in arr:
            curr_sum += i
            if curr_sum % 2:  
                res += 1 + even
                odd += 1
            else:
                res += odd
                even += 1
        return res % 1000000007
            
