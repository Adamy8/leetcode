class Solution:
    def increment(self,ch):
        ch = chr(ord(ch) + 1)
        if ch > 'z':
            ch = 'a'
        return ch
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        i, j = 0, 0
        while i<len(str1) and j<len(str2):
            if str1[i] == str2[j] or \
                self.increment(str1[i]) == str2[j]:
                i+=1
                j+=1
            else:
                i+=1
        if j==len(str2):
            return True
        else:
            return False
        