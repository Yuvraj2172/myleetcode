class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        left=0
        count =0

        occ = {'a':0, 'b':0, 'c':0}

        for right in range(len(s)):
            occ[s[right]]+=1

            while occ['a']>0 and occ['b'] > 0 and occ['c'] > 0:
                count += len(s) - right
                occ[s[left]] -=1
                left +=1
        return count