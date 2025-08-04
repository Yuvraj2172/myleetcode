from collections import defaultdict
class Solution:
    def totalFruit(self, arr: List[int]) -> int:
        mp = defaultdict(int)
        start,res = 0,0
        for end in range(len(arr)):
            mp[arr[end]] +=1
            while len(mp) > 2:
                mp[arr[start]] -=1
                if mp[arr[start]] == 0:
                    del mp[arr[start]]
                start+=1
            res = max(res, end - start+1)
        return res
