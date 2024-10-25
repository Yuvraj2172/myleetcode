class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()

        ans = [folder[0]]

        for i in range(1, len(folder)):
            temp = ans[-1] + '/'

            if not folder[i].startswith(temp):
                ans.append(folder[i])

        return ans