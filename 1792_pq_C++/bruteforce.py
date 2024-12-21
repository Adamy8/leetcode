from typing import List

class Solution:
    def ratioCal(self,classes) -> float:
        count = 0
        for i in range(len(classes)):
            count += (float(classes[i][0]/classes[i][1]))
        return count/len(classes)
    
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        while(extraStudents>0):
            classes.sort(key=lambda x:x[1])
            for i in range(len(classes)):
                if classes[i][0]<classes[i][1]:
                    classes[i][0]+=1
                    classes[i][1]+=1
                    extraStudents-=1
                    break
        
        return self.ratioCal(classes)
    

# fail, not exactly what question want