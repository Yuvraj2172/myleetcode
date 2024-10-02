class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        mp = {}
        unique_list = sorted(list(set(arr)))

        for i in range(len(unique_list)):
            mp[unique_list[i]] = i + 1
        
        for i in range(len(arr)):
            arr[i] = mp[arr[i]]

        return arr