class Solution:
    def dividePlayers(self, arr: List[int]) -> int:
        arr.sort()

        skill = arr[0] + arr[-1]
        ans = 0
        for i in range(len(arr)//2):
            temp = arr[i] + arr[-i - 1]

            if temp != skill:
                return -1
            
            ans += (arr[i] * arr[-i - 1])
        
        return ans