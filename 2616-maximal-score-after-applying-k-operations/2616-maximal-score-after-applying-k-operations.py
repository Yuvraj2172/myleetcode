class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        heapify(pq:=[-x for x in nums])
        ans = 0
        for i in range(k):
            ele = -heappop(pq)
            ans += ele

            heappush(pq, -((ele + 2 )//3))
            

        return ans