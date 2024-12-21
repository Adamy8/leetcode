class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        count = 0
        for num in spaces:
            num += count
            s = s[:num] + " " + s[num:]
            count+=1
        return s
    
# ! time limit exceeded