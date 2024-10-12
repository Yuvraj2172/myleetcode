class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        s = sorted([i[0] for i in intervals])
        e = sorted([i[1] for i in intervals])

        end_pointer = 0
        grp =0

        for start in s:
            if start > e[end_pointer]:
                end_pointer += 1
            else:
                grp +=1
        return grp

        