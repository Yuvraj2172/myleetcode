class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        s = sum(chalk)
        rem = k % s

        for i in range(len(chalk)):
            rem -= chalk[i]
            if rem < 0 : return i
        
        return -1
        