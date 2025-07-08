import bisect

class Solution:

    def __init__(self):
        self.events = []

    
    @cache
    def solve(self, i, k):
        if i >= len(self.events): 
            return 0
        if k <= 0: 
            return 0
        s, e, v = self.events[i]
        j = bisect.bisect(self.events, [e+1])
        return max(v + self.solve(j, k - 1), self.solve(i + 1, k))

    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort()
        self.events = events
        return self.solve(0, k)