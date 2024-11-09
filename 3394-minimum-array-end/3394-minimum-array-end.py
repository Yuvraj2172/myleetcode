class Solution:
    @staticmethod
    def minEnd(n: int, x: int) -> int:
        n -= 1
        c, m, mask = 0, 1, x ^ ((1 << (n.bit_length() + x.bit_length())) - 1)
        while mask:
            b = mask & -mask
            if n & m:
                c |= b
            mask -= b
            m <<= 1
        return x | c