class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        ans = []
        last = -1
        for i in range(len(words)):
            if groups[i] != last:
                ans.append(words[i])
                last = groups[i]
        return ans