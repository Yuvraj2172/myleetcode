class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        ans = 0
        for n in range(low, high + 1):
            str_n = str(n)

            if len(str_n) % 2 == 0:
                sfh = sum(int(d) for d in str_n[0:len(str_n) // 2])
                ssh = sum(int(d) for d in str_n[len(str_n) // 2 : ])
                if sfh == ssh:
                    ans += 1

        return ans