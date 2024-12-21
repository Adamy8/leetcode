from typing import List
from bisect import bisect_right

class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        # Sort events by end time
        events.sort(key=lambda x: x[1])

        max_sum = 0
        max_single = 0

        # Prefix max array
        prefix_max = []
        prefix_end = []

        for start, end, value in events:
            # Find the latest non-overlapping event using binary search
            idx = bisect_right(prefix_end, start - 1)

            # Consider two cases:
            # 1. Only the current event
            max_sum = max(max_sum, value)

            # 2. Current event + best previous non-overlapping event
            if idx > 0:
                max_sum = max(max_sum, value + prefix_max[idx - 1])

            # Update prefix arrays
            max_single = max(max_single, value)
            prefix_max.append(max_single)
            prefix_end.append(end)

        return max_sum


# Test cases
sol = Solution()

# Example cases
events1 = [[1, 3, 2], [4, 5, 2], [2, 4, 3]]
events2 = [[1, 3, 2], [4, 5, 2], [1, 5, 5]]
events3 = [[1, 5, 3], [1, 5, 1], [6, 6, 5]]
events4 = [[10, 83, 53], [63, 87, 45], [97, 100, 32], [51, 61, 16]]

print(sol.maxTwoEvents(events1))  # Output: 5
print(sol.maxTwoEvents(events2))  # Output: 5
print(sol.maxTwoEvents(events3))  # Output: 8
print(sol.maxTwoEvents(events4))  # Test custom case
