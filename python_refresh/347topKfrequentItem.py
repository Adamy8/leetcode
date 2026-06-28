import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        if not nums: return []
        dt = {}

        for num in nums:
            dt[num] = dt.get(num, 0) + 1
        
        heap = []
        for key, val in dt.items():
            heapq.heappush(heap, (-val,key))
        
        ans = []
        for _ in range(k):
            ans.append(heapq.heappop(heap)[1])
        return ans
# my sol, used heapq w negate val to get k largest, O(nlogk) time, O(n) space

# another way is use vector to store value at frequecy as index.
# might have same frequency, so we need to store a list of values at each frequency index. 
# Then we can iterate from the end of the vector to get the k largest frequency values. 
# This approach is O(n) time and O(n) space.