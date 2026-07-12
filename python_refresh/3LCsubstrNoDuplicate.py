class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s: return 0

        maxLength = 0
        charS = set()
        left = 0
        for right in range(len(s)):
            while s[right] in charS:
                charS.remove(s[left])
                # charS.discard()
                left+=1
            
            charS.add(s[right])
            maxLength = max(maxLength, right-left+1)
        return maxLength
# sliding window, two pointers, hash set. O(n) time, O(maxLength) space worst case On


# M2: sliding window and hashmap/dict. O(n) time, O(min(n, a)) space worst case On, where a is the size of the character set.
# they are almost the same to M1
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        max_length = left = 0
        count = {}

        for right, c in enumerate(s):
            count[c] = 1 + count.get(c, 0)
            while count[c] > 1:
                count[s[left]] -= 1
                left += 1
        
            max_length = max(max_length, right - left + 1)

        return max_length
    

# M3, record where each char is last seen
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length = 0
        left = 0
        last_seen = {}

        for right, c in enumerate(s):
            if c in last_seen and last_seen[c] >= left:
                left = last_seen[c] + 1
            
            max_length = max(max_length, right - left + 1)
            last_seen[c] = right

        return max_length
# O(n) time, O(1) space?.
