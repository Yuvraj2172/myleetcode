class Solution:
    def reverseVowels(self, s: str) -> str:
        st = {'a','e','i', 'o','u'}
        mp = []
        s = list(s)
        for i in range(len(s)):
            if s[i].lower() in st:
                mp.append([s[i], i])

        mp.reverse()
        
        i,j =0, len(mp) - 1

        while i < j:
            s[mp[i][1]], s[mp[j][1]] = s[mp[j][1]],s[mp[i][1]]
            i+=1
            j-=1
        return ''.join(s)