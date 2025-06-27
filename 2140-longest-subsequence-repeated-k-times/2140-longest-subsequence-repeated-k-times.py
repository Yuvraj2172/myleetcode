class Solution:
    def longestSubsequenceRepeatedK(self, s: str, k: int) -> str:
        from collections import Counter, deque

        # First, count frequencies of each character
        freq = Counter(s)
        
        # Prune characters which cannot appear k times in the repeated subsequence
        valid_chars = []
        for c in sorted(freq, reverse=True):
            if freq[c] >= k:
                valid_chars.append(c)

        # BFS to build candidate subsequences (start with "")
        queue = deque([""])
        res = ""
        
        while queue:
            cur = queue.popleft()
            
            for c in valid_chars:
                candidate = cur + c
                # If the repeated candidate can be subsequence of s
                if self.is_k_subsequence(s, candidate, k):
                    queue.append(candidate)
                    # Update result if candidate is longer or lexicographically larger
                    if len(candidate) > len(res) or (len(candidate) == len(res) and candidate > res):
                        res = candidate
        return res

    def is_k_subsequence(self, s, sub, k):
        """
        Check if sub * k is a subsequence of s.
        For example, sub="ab", k=2 => "ab"+"ab"="abab" must be a subsequence of s.
        """
        target = sub * k
        i = 0
        for ch in s:
            if ch == target[i]:
                i += 1
                if i == len(target):
                    return True
        return False