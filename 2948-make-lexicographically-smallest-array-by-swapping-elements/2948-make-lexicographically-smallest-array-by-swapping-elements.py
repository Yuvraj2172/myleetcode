class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        orig_idx = []
        for idx, value in enumerate(nums):
            orig_idx.append([value, idx])
        orig_idx.sort(key = lambda x : x[0])

        orig_idx.append([2 * 10 ** 9 + 1, 0])

        gp = [orig_idx[0][0]]
        gp_idx = [orig_idx[0][1]]

        for ele in range(1, len(orig_idx)):
            curr = orig_idx[ele][0]
            prev = orig_idx[ele - 1][0]
            curr_idx = orig_idx[ele][1]

            if curr - prev > limit:
                gp_idx.sort()
                for i in range(len(gp)):
                    nums[gp_idx[i]] = gp[i]
                gp, gp_idx = [],[]
            gp.append(curr)
            gp_idx.append(curr_idx)
        return nums