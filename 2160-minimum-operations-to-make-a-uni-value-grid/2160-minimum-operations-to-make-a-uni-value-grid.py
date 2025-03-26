class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        arr = [val for row in grid for val in row]
        print(arr)
        arr.sort()

        ans = 0
        median = arr[len(arr)//2]
        for ele in arr:
            diff = abs(median - ele)
            if diff % x != 0:
                return -1
            ans += diff//x
        return ans