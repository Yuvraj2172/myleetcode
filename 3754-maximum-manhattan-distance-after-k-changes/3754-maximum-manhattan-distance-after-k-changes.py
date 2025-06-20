class Solution:
    def helper(self, s):
        x, y = 0, 0
        mx = 0
        for d in s:
            if d == 'N':
                y += 1
            elif d == 'S':
                y -= 1
            elif d == 'E':
                x += 1
            else:
                x -= 1
            mx = max(mx, abs(x) + abs(y))
        return mx

    def maxDistance(self, s: str, k: int) -> int:
        ans = 0
        s = list(s)

        temp = s[:] 
        x = k
        for i in range(len(temp)):
            if temp[i] == 'N' and x > 0:
                temp[i] = 'S'
                x -= 1
            elif temp[i] == 'E' and x > 0:
                temp[i] = 'W'
                x -= 1
        ans = max(ans, self.helper(temp))

        temp = s[:] 
        x = k
        for i in range(len(temp)):
            if temp[i] == 'N' and x > 0:
                temp[i] = 'S'
                x -= 1
            elif temp[i] == 'W' and x > 0:
                temp[i] = 'E'
                x -= 1
        ans = max(ans, self.helper(temp))

        temp = s[:] 
        x = k
        for i in range(len(temp)):
            if temp[i] == 'S' and x > 0:
                temp[i] = 'N'
                x -= 1
            elif temp[i] == 'W' and x > 0:
                temp[i] = 'E'
                x -= 1
        ans = max(ans, self.helper(temp))

        temp = s[:] 
        x = k
        for i in range(len(temp)):
            if temp[i] == 'S' and x > 0:
                temp[i] = 'N'
                x -= 1
            elif temp[i] == 'E' and x > 0:
                temp[i] = 'W'
                x -= 1
        ans = max(ans, self.helper(temp))

        return ans
