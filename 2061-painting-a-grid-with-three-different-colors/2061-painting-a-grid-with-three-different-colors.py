from itertools import product

class Solution:
    def colorTheGrid(self, m: int, n: int) -> int:
        MOD = 10**9 + 7

        # Step 1: Generate valid column states
        def is_valid(state):
            for i in range(1, len(state)):
                if state[i] == state[i - 1]:
                    return False
            return True

        colors = [0, 1, 2]  # 0: Red, 1: Green, 2: Blue
        valid_states = [state for state in product(colors, repeat=m) if is_valid(state)]
        state_count = len(valid_states)

        # Step 2: Build compatibility map
        compat = [[] for _ in range(state_count)]
        for i in range(state_count):
            for j in range(state_count):
                if all(a != b for a, b in zip(valid_states[i], valid_states[j])):
                    compat[i].append(j)

        # Step 3: Dynamic Programming
        dp = [1] * state_count

        for col in range(1, n):
            new_dp = [0] * state_count
            for i in range(state_count):
                for j in compat[i]:
                    new_dp[i] = (new_dp[i] + dp[j]) % MOD
            dp = new_dp

        return sum(dp) % MOD
