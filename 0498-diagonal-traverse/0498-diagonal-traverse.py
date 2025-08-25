class Solution:
    def findDiagonalOrder(self, g: List[List[int]]) -> List[int]:
        return [v for _,_,v in sorted((i+j,(j,i)[i+j&1],v)
            for i,r in enumerate(g) for j,v in enumerate(r))]