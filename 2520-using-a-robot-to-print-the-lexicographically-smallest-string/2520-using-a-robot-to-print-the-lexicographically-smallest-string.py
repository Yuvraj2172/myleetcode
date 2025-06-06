class Solution:
    def robotWithString(self, s: str) -> str:
        n = len(s)
        min_char = [None] * n
        min_char[-1] = s[-1]
        for i in range(n - 2, -1, -1):
            min_char[i] = min(s[i], min_char[i + 1])

        stack = []
        result = []

        for i in range(n):
            stack.append(s[i])
            while stack and (i == n - 1 or stack[-1] <= min_char[i + 1]):
                result.append(stack.pop())

        return ''.join(result)