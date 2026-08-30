class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        n = len(nums)

        mx_idx, mn_idx = nums.index(max(nums)), nums.index(min(nums))
        if mx_idx == mn_idx :
            return len(nums)
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