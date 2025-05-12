class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        mpp = [0] * 10
        for d in digits:
            mpp[d]+=1
        res = []

        for i in range(1,10):
            if mpp[i] == 0:
                continue
            mpp[i] -= 1
            for j in range(10):
                if mpp[j] == 0:
                    continue
                mpp[j] -= 1
                for k in range(0,10,2):
                    if mpp[k] == 0:
                        continue
                    res.append(100 * i + 10 * j + k)
                mpp[j]+=1
            mpp[i]+=1
        return res
