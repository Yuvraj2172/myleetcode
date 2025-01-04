class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        l=set(s)
        cnt=0
        for x in l :
            left,right=s.index(x),s.rindex(x)
            b=set()
            if left!=right : b=set(s[left+1:right])
            cnt+=len(b)
        return cnt