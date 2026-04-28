class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        ans=0
        arr = [val for row in grid for val in row]
        arr.sort()

        median = arr[len(arr) // 2]

        for ele in arr:
            diff = abs(ele - median)
            if diff % x != 0:
                return -1
            else:
                ans+= (diff // x)
        return ans
        