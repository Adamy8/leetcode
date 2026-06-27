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
arr.append(4)
arr.pop()   # pop last element, O(1)
arr.pop(0)      # = pop at index 0, bad cuz O(n), should use deque.popleft()
arr[i]
len(arr)
arr[-1]  # last element
arr.insert(i, x)
arr.sort()
arr.reverse()
arr.remove(x)  # remove first occurrence of x
arr.count(x)  # count occurrences of x
arr.index(x)  # index of first occurrence of x
max(arr)       # max element in list
min(arr)
sum(arr)    # sum of elements in list
if not arr:  # check if list is empty      == c++ if(arr.empty())
    ...

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
q.append(5)         # add to back, O(1)
q.appendleft(0)     # add to front, O(1)
q.popleft()         # pop first element, O(1)
print(q)
q.pop()           # pop last element, O(1)

# string
s = "abc"
len(s)
s[0]  # first character
s[-1]  # last character
s[1:3]  # substring from index 1 to 2. NOT INCLUDE 3!
new_str = s[::-1]  # reverse string, python string are immutable. O(n)time and space
s.lower() # convert to lowercase
s.upper() # convert to uppercase
s.strip() # remove leading and trailing whitespace


# stack
stack = []
stack.append(x)
stack.pop()     # pop last element, O(1)

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

# ternary
return low if nums[low] == target else -1

# BigO:
# list append: O(1) average
# list pop(): O(1)
# list pop(0): O(n)  # avoid
# dict get/set: O(1) average
# set add/search: O(1) average
# deque append/popleft: O(1)
# heap push/pop: O(log n)
# sort: O(n log n)