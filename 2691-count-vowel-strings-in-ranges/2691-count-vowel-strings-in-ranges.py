class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        n = len(words)
        pref = [0] * (n + 1)
        ans = []

        vowels = {'a', 'e', 'i', 'o', 'u'}

        for i in range(n):
            pref[i+1] = pref[i]

            if words[i][0] in vowels and words[i][-1] in vowels:
                pref[i+1] += 1
            
        for q in queries:
            left = q[0]
            right = q[1]

            ans.append(pref[right + 1] - pref[left])
        
        return ans