class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        
        unique_list = sorted(list(set(arr)))
        mp = {}

        for i in range(len(unique_list)):
            mp[unique_list[i]] = i+1

        for i in range(len(arr)):
            arr[i] = mp[arr[i]]

        return arr