from typing import List

class Solution:
    def findMaxSum(nums):
        # Handle case where there are fewer than 3 elements
        if len(nums) < 3:
            return 0
        
        # Initialize the maxSum array with the base cases
        maxSum = [0] * len(nums)
        
        # Base cases
        maxSum[0] = nums[0]
        maxSum[1] = max(nums[0], nums[1])
        maxSum[2] = max(nums[0] + nums[2], nums[1])

        # Fill the maxSum array using dynamic programming
        for i in range(3, len(nums)):
            maxSum[i] = max(maxSum[i-2] + nums[i], maxSum[i-3] + nums[i], maxSum[i-1])

        # The maximum sum is either at the last or second last position
        return max(maxSum[-1], maxSum[-2])

    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        sums = [ 0 for _ in range(len(nums) - k + 1)]
        for i in range(len(sums)):
            for j in range(k):
                sums[i] += nums[i+j]
        
