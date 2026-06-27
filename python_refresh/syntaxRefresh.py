# Main data strutures:
# list
# dict
# set
# deque
# heapq

import math
math.sqrt(25)
math.ceil(3.2)
math.floor(3.8)

# vector/list
arr = []
arr.append(x)
arr.pop()
arr.pop(0)      # = pop at index 0, bad cuz O(n), should use deque.popleft()
arr[i]
len(arr)

# hashmap/dict
d = {}
d[key] = value
if key in d:
    ...

# Hash set
s = set()
s.add(x)
if x in s:
    ...

# deque
from collections import deque
q = deque()
q.append(5)
q.appendleft(0)
q.popleft()
print(q)

# stack
stack = []
stack.append(x)
stack.pop()

# heapq = C++ priority_queue
import heapq
heapq.heappush(heap, x)
heapq.heappop(heap)

# sort
arr.sort()
arr.sort(reverse=True)
arr.sort(key=lambda x: x[1])
# creates a new sorted list
new_arr = sorted(arr)
new_arr = sorted(arr, reverse=True)


# BigO:
# list append: O(1) average
# list pop(): O(1)
# list pop(0): O(n)  # avoid
# dict get/set: O(1) average
# set add/search: O(1) average
# deque append/popleft: O(1)
# heap push/pop: O(log n)
# sort: O(n log n)