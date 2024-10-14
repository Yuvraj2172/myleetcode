import math
class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        heapify(pq:=[-x for x in nums])

        ans = 0

        for i in range(k):
            x = -heappop(pq)
            ans += x

            heappush(pq, -math.ceil((x) / 3))
        
        return ans