class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        parent = [-1] * 26

        def find(x):
            if parent[x] == -1:
                return x
            parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            px, py = find(x), find(y)
            if px == py:
                return
            parent[max(px, py)] = min(px, py)

        for a, b in zip(s1, s2):
            union(ord(a) - ord('a'), ord(b) - ord('a'))

        result = []
        for ch in baseStr:
            result.append(chr(find(ord(ch) - ord('a')) + ord('a')))

        return ''.join(result)
