class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        current_st = 0
        mx = max(asteroids) 
        while asteroids:
            left_to_process = []
            for ele in asteroids:
                if mass < ele:
                    left_to_process.append(ele)
                else:
                    mass += ele
                    if mass >= mx:
                        return True
            if len(left_to_process) == len(asteroids):
                return False
            asteroids = left_to_process
        
        return True
            