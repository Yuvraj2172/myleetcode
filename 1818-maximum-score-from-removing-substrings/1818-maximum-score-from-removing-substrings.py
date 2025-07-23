class Solution:
    def maximumGain(self, s: str, abScore: int, baScore: int) -> int:
        totalScore = 0
        firstChar, secondChar = 'a', 'b'
        firstCount, secondCount = 0, 0

        # \U0001f4a5 Prioritize the higher scoring pair
        if abScore < baScore:
            abScore, baScore = baScore, abScore
            firstChar, secondChar = 'b', 'a'

        for ch in s:
            if ch == firstChar:
                firstCount += 1
            elif ch == secondChar:
                if firstCount > 0:
                    firstCount -= 1
                    totalScore += abScore
                else:
                    secondCount += 1
            else:
                # \U0001f527 Resolve remaining lower-scoring pairs
                totalScore += min(firstCount, secondCount) * baScore
                firstCount = 0
                secondCount = 0

        # ✅ Handle leftovers
        totalScore += min(firstCount, secondCount) * baScore

        return totalScore