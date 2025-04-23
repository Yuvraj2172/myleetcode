class Solution:
    def digit_sum(self,n):
        s = 0
        while n != 0:
            s += n % 10
            n //= 10
        return s
    def countLargestGroup(self, n: int) -> int:
        mp = {}
        mx = 0
        for i in range(1, n + 1):
            sm = self.digit_sum(i)
            mp[sm] = mp.get(sm,0) + 1
            mx = max(mx, mp[sm])

        ans = 0
        for k,v in mp.items():
            if v == mx:
                ans += 1
        return ans