class Solution:
    def triangularSum(self, arr: List[int]) -> int:
        n = len(arr)

        for size in range(n, -1, -1):
            for i in range(size- 1):
                arr[i] = (arr[i] + arr[i+1]) % 10
        return arr[0]
        