# this is from the top comment of this question
# It's crazy

class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        sum = 0
        count = 0
        for i in range(len(arr)):
            sum += arr[i]
            temp = i*(i+1)/2
            if temp == sum:
                count+=1
        return count