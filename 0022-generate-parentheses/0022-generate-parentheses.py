class Solution:
    def helper(self, open, close, s,res,n):
        if open == close and open + close == 2 * n:
            res.append(s)
            return 
        if open < n :
            self.helper(1 + open, close, s + '(',res, n)
        if open  > close:
            self.helper(open, 1 + close,s +  ')',res, n)
    def generateParenthesis(self, n: int) -> list[str]:
        res = []
        self.helper(0,0,"", res,n)
        return res