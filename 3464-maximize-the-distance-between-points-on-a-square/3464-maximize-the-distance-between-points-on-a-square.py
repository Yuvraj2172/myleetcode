from typing import List

class Solution:
    def maxDistance(self, side: int, points: List[List[int]], k: int) -> int:
        # map each point to its coordinate along the perimeter (clockwise from (0,0))
        P = 4 * side
        t = []
        for x, y in points:
            if y == 0 and 0 <= x <= side:          # bottom edge
                t.append(x)
            elif x == side and 0 <= y <= side:     # right edge
                t.append(side + y)
            elif y == side and 0 <= x <= side:     # top edge
                t.append(2 * side + (side - x))
            else:                                  # left edge
                t.append(3 * side + (side - y))
        t.sort()
        n = len(t)
        t_ext = t + [x + P for x in t]

        # Check if we can choose k points with minimum circular distance >= D
        def feasible(D: int) -> bool:
            if D == 0:
                return True
            # next2[i] = smallest index > i with distance >= D
            m = len(t_ext)
            nxt = [-1] * m
            j = 0
            for i in range(m):
                if j <= i:
                    j = i + 1
                while j < m and t_ext[j] - t_ext[i] < D:
                    j += 1
                if j < m:
                    nxt[i] = j
            # try every point as the starting point
            for start in range(n):
                cur = start
                cnt = 1
                while cnt < k:
                    nxt_idx = nxt[cur]
                    if nxt_idx == -1 or nxt_idx >= start + n:  # do not take the start point again
                        break
                    cur = nxt_idx
                    cnt += 1
                if cnt == k:
                    # distance from last chosen point back to start must also be >= D
                    if t_ext[cur] - t_ext[start] <= P - D:
                        return True
            return False

        # binary search the maximum D
        lo, hi = 0, P
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if feasible(mid):
                lo = mid
            else:
                hi = mid - 1
        return lo