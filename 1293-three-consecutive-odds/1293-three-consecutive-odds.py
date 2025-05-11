class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        n = len(arr)
        if n < 3 :
            return False
        if n == 3:
            if arr[0] % 2 == 1 and arr[1] % 2 == 1 and arr[2] % 2 == 1:
                return True
        for i in range(n - 2):
            if arr[i] % 2 == 1 and arr[i+1] % 2 == 1 and arr[i+2] % 2 == 1:
                return True
        return False