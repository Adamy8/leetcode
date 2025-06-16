# easy
# 1768. Merge Strings Alternately

class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        result=''
        i = 0
        while i<len(word1) and i<len(word2):
            result += (word1[i])
            result += (word2[i])
            i+=1
        j = i
        while i<len(word1) :
            result += (word1[i])
            i+=1
        while(j<len(word2)):
            result += (word2[j])
            j+=1
        return result
        