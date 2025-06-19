class Solution:
    def help(self,s):
        mx = 0
        x,y =0 ,0
        for i in s:
            if i == 'N':
                y +=1
            elif i == 'E':
                x +=1
            elif i == 'W':
                x -=1
            else:
                y -=1
            mx = max(mx, abs(x) + abs(y))
        return mx
    def maxDistance(self, s: str, k: int) -> int:
        temp = list(s)
        x = k
        ans =0
        # N to S and E to W
        for i in range(len(temp)):
            if temp[i] == 'N' and x > 0:
                temp[i] = 'S'
                x -= 1
            elif temp[i] == 'E' and x > 0:
                temp[i] = 'W'
                x-=1
        ans = max(ans, self.help(temp))

        temp = list(s)
        x = k
        # N to S and W to E
        for i in range(len(temp)):
            if temp[i] == 'N' and x > 0:
                temp[i] = 'S'
                x -= 1
            elif temp[i] == 'W' and x > 0:
                temp[i] = 'E'
                x-=1
        ans = max(ans, self.help(temp))
        temp = list(s)
        x = k
        # S to N and W to E
        for i in range(len(temp)):
            if temp[i] == 'S' and x > 0:
                temp[i] = 'N'
                x -= 1
            elif temp[i] == 'W' and x > 0:
                temp[i] = 'E'
                x-=1
        ans = max(ans, self.help(temp))

        temp = list(s)
        x = k
        # S to N and E to W
        for i in range(len(temp)):
            if temp[i] == 'S' and x > 0:
                temp[i] = 'N'
                x -= 1
            elif temp[i] == 'E' and x > 0:
                temp[i] = 'W'
                x-=1
        ans = max(ans, self.help(temp))

        return ans