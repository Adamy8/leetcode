class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        targets = {}
        for i, num in enumerate(nums):
            if num in targets:
                return [targets[num], i]
            curTarget = target-num
            targets[curTarget] = i
        return []
# my sol, hashmap, O(n) time, O(1) space

