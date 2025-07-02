MOD = 10**9 + 7

class Solution:
    def possibleStringCount(self, word: str, k: int) -> int:
        # Step 1: Group consecutive letters into their counts
        groups = self.getConsecutiveLetters(word)

        # Step 2: Calculate total combinations by multiplying group sizes
        totalCombinations = 1
        for g in groups:
            totalCombinations = (totalCombinations * g) % MOD

        # Step 3: Early exit if k <= number of groups
        if k <= len(groups):
            return totalCombinations

        # Step 4: Initialize DP array where dp[i] = number of ways to form string of length i
        dp = [0] * k
        dp[0] = 1  # Base case: one way to form an empty string

        # Step 5: Process each group and update dp using sliding window
        for i in range(len(groups)):
            group = groups[i]
            new_dp = [0] * k
            window_sum = 0

            # Step 5.1: For each possible length j, update new_dp[j] with window sum
            for j in range(i, k):
                new_dp[j] = (new_dp[j] + window_sum) % MOD
                window_sum = (window_sum + dp[j]) % MOD

                # Step 5.2: Maintain window size equal to group size
                if j >= group:
                    window_sum = (window_sum - dp[j - group] + MOD) % MOD

            dp = new_dp  # Move to next group

        # Step 6: Sum up all dp values (these are invalid combinations with length < k)
        invalid = sum(dp) % MOD

        # Step 7: Subtract invalid from total to get valid combinations
        return (totalCombinations - invalid + MOD) % MOD

    def getConsecutiveLetters(self, word: str) -> list:
        # Step 1 continued: Form the list of group sizes
        if not word:
            return []
        
        groups = []
        count = 1
        for i in range(1, len(word)):
            if word[i] == word[i - 1]:
                count += 1
            else:
                groups.append(count)
                count = 1
        groups.append(count)
        return groups