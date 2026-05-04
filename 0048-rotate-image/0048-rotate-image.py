class Solution:
    def rotate(self, arr: List[List[int]]) -> None:
            n = len(arr)

            for i in range(n):
                for j in range(i+1,n):
                    arr[i][j], arr[j][i] = arr[j][i], arr[i][j]
            for i in range(n):
                arr[i].reverse()
            return arr