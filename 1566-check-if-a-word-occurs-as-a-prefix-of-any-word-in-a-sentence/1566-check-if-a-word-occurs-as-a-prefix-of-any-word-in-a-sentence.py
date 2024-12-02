class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        l = sentence.split(' ')

        for i in range(len(l)):
            print(l[i])
            if l[i].startswith(searchWord):
                return i + 1
        return -1