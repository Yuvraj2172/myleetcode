class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        words1 = sentence1.split()
        words2 = sentence2.split()

        if len(words1) < len(words2) : 
            words1, words2 = words2, words1

        start = 0
        end = 0

        n1=len(words1)
        n2 = len(words2)

        while start < n2 and words1[start] == words2[start]:
            start+=1
        
        while end < n2 and words2[n2 - end -1] == words1[n1 - end - 1]:
            end +=1

        return True if start + end >= n2 else False
        