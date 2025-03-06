class Solution:
    def findMissingAndRepeatedValues(self, arr: List[List[int]]) -> List[int]:
        st = set()

        n = len(arr)
        dup, miss = -1,-1
        for i in range(n):
            for j in range(n):
                if arr[i][j] in st:
                    dup = arr[i][j]
                st.add(arr[i][j])

        print(st)
        for i in range(1,pow(n,2)+1):
            print(i)
            if i not in st:
                miss = i
                break

        return [dup,miss]