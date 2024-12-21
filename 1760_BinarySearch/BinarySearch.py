import math
from typing import List

class Solution:
    def is_feasible(self,nums,maxBallInBag,maxOpera):
        opera = 0
        if maxBallInBag == 0:
            return False
        for num in nums:
            if num > maxBallInBag:
                # opera += (num//maxBallInBag -1 + (0 if num % maxBallInBag == 0 else 1))

                # 上面这行可以直接用ceil解决：
                opera += math.ceil(num/maxBallInBag) -1
                
        if opera > maxOpera:
            return False
        return True

    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        # max_size = len(nums) + maxOperations
        nums.sort()
        low,high = 1,nums[-1]
        result = 0
        while low <= high:
            mid = low + (high-low)//2
            print(f"low: {low}, high: {high}, mid: {mid}")
            if self.is_feasible(nums,mid,maxOperations):
                print(f"{mid} is feasible")
                result = mid
                high = mid-1
            else:
                print(f"{mid} is not feasible")
                low = mid+1
            print()
        return result
        
# for test only
sol = Solution()
# nums = [9]
# maxOperations = 2

nums = [2,4,8,2]
maxOperations = 4

# nums = [1]
# maxOperations = 1
print(sol.minimumSize(nums,maxOperations))