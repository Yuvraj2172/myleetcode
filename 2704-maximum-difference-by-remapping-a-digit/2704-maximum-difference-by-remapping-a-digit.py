class Solution:
    def minMaxDifference(self, num: int) -> int:
        num = str(num)

        replace_char = ''
        for c in num:
            if c != '9':
                replace_char = c
                break
        replace_for_min = num[0]
        max_num = ['9' if c == replace_char else c for c in num]
        min_num = ['0' if c == replace_for_min else c for c in num]
        print(max_num)
        print(min_num)
        return int(''.join(max_num)) - int(''.join(min_num))