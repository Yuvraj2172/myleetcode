class Solution:
    def maxDistance(self, arr: List[int]) -> int:
        ans,n = -float('inf'), len(arr)
        for i in range(n):
            temp = 0
            for j in range(i+1,n):
                if arr[i] != arr[j]:
                    temp = max(temp, abs(j - i))
            ans = max(ans, temp)
        print(ans)
        return ans