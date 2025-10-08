class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        ans = [0] * len(spells)
        potions.sort()
        for i in range(len(spells)):
            left, right = 0, len(potions) - 1

            while left <= right:
                mid = (left + right) >> 1
                power = potions[mid] * spells[i]
                if power >= success:
                    right = mid - 1
                else:
                    left = mid  +1
            ans[i] = len(potions) - left
        return ans