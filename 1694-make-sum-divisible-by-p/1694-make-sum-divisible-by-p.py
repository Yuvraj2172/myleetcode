class Solution:
    def minSubarray(self, arr: List[int], p: int) -> int:
        s = sum(arr)
        rem = s % p

        if rem == 0: return 0

        mp = {0 : -1}
        prefsum = 0

        minlen = len(arr)
        for i, val in enumerate(arr):
            prefsum += val
            currmod = prefsum % p
            targetmod = (currmod - rem + p)%p

            if targetmod in mp:
                minlen = min(minlen, i - mp[targetmod])
            
            mp[currmod] = i

        return minlen if minlen < len(arr) else -1