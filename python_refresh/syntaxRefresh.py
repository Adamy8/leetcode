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
5/2 = 2.5
5//2 = 2

# vector/list, underlying data structure is a dynamic array, which is a contiguous block of memory that can be resized. When the array is full and a new element is added, a new larger array is created and the elements are copied over. This resizing operation takes O(n) time, but it happens infrequently, so the average time complexity for adding an element to the end of the list is O(1). The time complexity for accessing an element by index is O(1), but inserting or deleting an element at an arbitrary position takes O(n) time because all subsequent elements need to be shifted.
arr = []
arr.append(4)
arr.pop()   # pop last element, O(1)
arr.pop(0)      # = pop at index 0, bad cuz O(n), should use deque.popleft()
arr[i]
len(arr)
arr[-1]  # last element
arr.insert(i, x)
arr.sort()    # inplace!
new_arr = sorted(arr)  # not inplace
arr.reverse()   # same with ::-1 but its inplace, O(n) time and O(1) space
new_array = arr[::-1]  # reverse list, O(n) time and space
arr.remove(x)  # remove first occurrence of x
arr.count(x)  # count occurrences of x
arr.index(x)  # index of first occurrence of x
max(arr)       # max element in list
min(arr)
sum(arr)    # sum of elements in list
if not arr:  # check if list is empty      == c++ if(arr.empty())
    ...

# hashmap/dict = C++ unordered_map - underlying hash table, which is an array of linked lists. The hash function maps keys to indices in the array, and the linked list at each index stores the key-value pairs that hash to that index. The average time complexity for inserting, deleting, and searching for a key-value pair is O(1), but in the worst case, it can be O(n) if all keys hash to the same index. Python's dict implementation uses open addressing with linear probing to resolve collisions, which means that when a collision occurs, the next available slot in the array is used to store the key-value pair.
d = {}    #==  d = dict()
d[key] = value
d.pop(key)   # remove key and return value, raise KeyError if not found
d.popitem()  # remove arbitrary key and return value, raise KeyError if dict is empty
if key in d:        # O(1) average
    ...
# traverse dict:
for key, value in d.items():
    ...
d.items()  # return a view object that displays a list of a dictionary's key-value tuple pairs
d.get(key, default)  # return value if key exists, else return default

# Hash set
s = set()
s.add(x)        # O(1) average
s.remove(x)     # O(1) average, raise KeyError if not found
s.discard(x)    # O(1) average, do nothing if not found
s.clear()      # O(1) average
s.pop()        # O(1) average, remove and return an arbitrary element
if x in s:      # O(1) average
    ...

# deque
from collections import deque
q = deque()
q.append(5)         # add to back, O(1)
q.appendleft(0)     # add to front, O(1)
q.popleft()         # pop first element, O(1)
print(q)
q.pop()           # pop last element, O(1)

# heapq = C++ priority_queue, underlying data structure is a binary heap, which is a complete binary tree. The smallest element is always at the root of the tree. Python's heapq module provides an implementation of the min-heap. If you want a max-heap, you can invert the values by multiplying them by -1.
import heapq
heap = []  # heap is just a list, but heapq functions maintain the heap property
heapq.heappush(heap, x)     # push x onto heap, O(log n)
heapq.heappop(heap)         # pop smallest element from heap, O(log n)
# for tuples:   the first element is used for comparison, so you can use a tuple to store both the key and value.
heapq.heappush(heap, (key,val))    # O(log n), the first element of the tuple is used for comparison
smallestTuple = heapq.heappop(heap)         # O(log n), return the tuple with the smallest first element

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


# stack - implemented w list
stack = []
stack.append(x)
stack.pop()     # pop last element, O(1)

# python pair
pair = (1, 2)


# sort
arr.sort()
arr.sort(reverse=True)
arr.sort(key=lambda x: x[1])
# creates a new sorted list
new_arr = sorted(arr)
new_arr = sorted(arr, reverse=True)

# ternary
\return low if nums[low] == target else -1

# is vs ==
a = [1, 2]
b = [1, 2]
print(a == b)  # True   value equality
print(a is b)  # False  identity equality, not the same object in memory

# BigO:
# list append: O(1) average
# list pop(): O(1)
# list pop(0): O(n)  # avoid
# dict get/set: O(1) average
# set add/search: O(1) average
# deque append/popleft: O(1)
# heap push/pop: O(log n)
# sort: O(n log n)