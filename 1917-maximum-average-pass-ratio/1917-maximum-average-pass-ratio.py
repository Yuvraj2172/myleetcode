class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        ans = 0
        def gain(p,t):
            return ((p +1) / (t + 1) - (p / t))
        heap = []
        for p,t in classes:
            heapq.heappush(heap,(-gain(p,t), p,t))
        for _ in range(extraStudents):
            g,p,t = heapq.heappop(heap)
            p +=1
            t +=1
            heapq.heappush(heap, (-gain(p,t), p,t))
        while heap:
            _,p,t = heapq.heappop(heap)
            ans += (p / t)
        return ans/len(classes)