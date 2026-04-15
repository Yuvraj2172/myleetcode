class Solution:
    def closestTarget(self, arr: List[str], target: str, si: int) -> int:
        ans = float('inf')
        n = len(arr)
        for i in range(n):
            if arr[i] == target:
                dist_left = abs(si - i)
                dist_right = n - dist_left
                temp = min(dist_left, dist_right)
                ans = min(ans, temp)
        return ans if ans != float('inf') else -1