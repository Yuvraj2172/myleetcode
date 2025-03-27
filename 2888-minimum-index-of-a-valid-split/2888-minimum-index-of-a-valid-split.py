class Solution:
    def minimumIndex(self,nums):
        n = len(nums)
        if n < 2:
            return -1

        # Find the dominant element using Moore's Voting Algorithm
        dominant = nums[0]
        count = 1
        for i in range(1, n):
            if nums[i] == dominant:
                count += 1
            else:
                count -= 1
                if count == 0:
                    dominant = nums[i]
                    count = 1

        # Verify the dominant element (optional but recommended)
        dominant_count = 0
        for num in nums:
            if num == dominant:
                dominant_count += 1
        if dominant_count <= n // 2:
            return -1  # Invalid input (should not happen, but good to check)

        # Check for valid splits
        left_count = 0
        for i in range(n - 1):
            if nums[i] == dominant:
                left_count += 1

            if left_count > (i + 1) // 2 and (dominant_count - left_count) > (n - i - 1) // 2:
                return i

        return -1