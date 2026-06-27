class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return self.recur(nums, 0, len(nums), target)

    def recur(self,nums, low, high, target) -> int:
        if low >= high: return -1
        if low == high-1: return low if nums[low]==target else -1

        mid = low + (high-low)//2
        if nums[mid]==target: return mid
        elif nums[mid] > target:
            return self.recur(nums,low,mid,target)
        else:
            return self.recur(nums,mid+1,high,target)
# my solution, O(logn) time, O(logn) space due to recursion stack. Can be improved to O(1) space by using iterative approach.

# professional clean version for recur:  used nested helper func instead of class method
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def binary_search(left: int, right: int) -> int:
            if left > right:
                return -1

            mid = (left + right) // 2

            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                return binary_search(mid + 1, right)
            return binary_search(left, mid - 1)

        return binary_search(0, len(nums) - 1)

# iterative version, O(logn) time, O(1) space
l, r = 0, len(nums) - 1

while l <= r:
    mid = (l + r) // 2

    if nums[mid] == target:
        return mid
    elif nums[mid] < target:
        l = mid + 1
    else:
        r = mid - 1

return -1