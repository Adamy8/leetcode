from typing import List

class Solution:
    def contains_only_and_all(self,arr, head, tail):
        arr2 = list(range(tail,head))
        sublist = arr[tail:head]

        return set(sublist) == set(arr2) and all(sublist.count(x) >= arr2.count(x) for x in arr2)

    def maxChunksToSorted(self, arr: List[int]) -> int:
        count = 0
        head = 1
        tail = 0
        while head <= len(arr):
            if self.contains_only_and_all(arr,head,tail):
                count += 1
                tail = head
            head += 1
        return count
        