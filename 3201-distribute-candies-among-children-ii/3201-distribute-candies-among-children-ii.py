from math import comb

class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        def count_ways(total, variables):
            if total < 0:
                return 0
            return comb(total + variables - 1, variables - 1)

        total = count_ways(n, 3)

        over_1 = count_ways(n - (limit + 1), 3)
        over_2 = count_ways(n - 2 * (limit + 1), 3)
        over_3 = count_ways(n - 3 * (limit + 1), 3)

        subtract1 = 3 * over_1
        add2 = 3 * over_2

        result = total - subtract1 + add2 - over_3
        return result
