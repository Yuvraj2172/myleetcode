class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return len(nums)
        mx, mn = max(nums), min(nums)
        n = len(nums)

        mx_idx, mn_idx = len(nums),len(nums)
        for i in range(len(nums)):
            if nums[i] == mx:
                mx_idx = i
            if nums[i] == mn:
                mn_idx = i 
        
        ans = min(
            # remove front
            max(mx_idx, mn_idx) + 1,
            # remove back
            max(n - 1 - mx_idx, n -1 - mn_idx) + 1,
            # try both
            min(
                mx_idx + 1 + n - mn_idx,
                mn_idx + 1 + n - mx_idx,
            )

        )
        
        print(ans, mn_idx, mx_idx)   
        return ans