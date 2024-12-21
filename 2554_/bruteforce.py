from typing import List

class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        tot,count = 0,0
        for i in range(1 , n + 1):
            if i in banned:
                continue
            if (tot+i) > maxSum:
                return count
            tot += i
            count += 1
        return count

# test only
sol = Solution()
banned = [11]
n = 7
maxSum = 50

print(sol.maxCount(banned,n,maxSum))
