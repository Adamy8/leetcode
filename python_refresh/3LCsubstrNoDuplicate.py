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
