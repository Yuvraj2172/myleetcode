class Solution:
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        # Convert to strings for digit manipulation
        s_start = str(start - 1)
        s_finish = str(finish)
        
        # Use helper function to count powerful integers <= n
        return self.count_powerful(s_finish, s, limit) - self.count_powerful(s_start, s, limit)
    
    def count_powerful(self, num: str, suffix: str, limit: int) -> int:
        # If num is shorter than the required suffix, no powerful integers exist
        if len(num) < len(suffix):
            return 0
            
        # If lengths match, check if num >= suffix
        if len(num) == len(suffix):
            return 1 if num >= suffix else 0
        
        result = 0
        prefix_len = len(num) - len(suffix)
        
        # Process digit by digit for the prefix part
        for i in range(prefix_len):
            digit = int(num[i])
            
            # If current digit exceeds limit, we can't use digits beyond limit
            if digit > limit:
                # All remaining positions filled with digits 0..limit
                result += (limit + 1) ** (prefix_len - i)
                return result
                
            # Count valid numbers with digits smaller than current digit
            result += digit * (limit + 1) ** (prefix_len - i - 1)
        
        # Check if the suffix part of num is >= required suffix
        if num[-len(suffix):] >= suffix:
            result += 1
            
        return result