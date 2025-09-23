class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1, v2 = version1.split('.'), version2.split('.')
        n,m = len(v1), len(v2)
        for i in range(max(n,m)):
            vs1 = int(v1[i]) if i < n else 0
            vs2 = int(v2[i]) if i < m else 0
            if vs1 < vs2:
                return -1
            elif vs1 > vs2:
                return 1
        return 0