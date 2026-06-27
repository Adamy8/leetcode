# my solution
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        strDict = {}
        # strDict[ chararray ] = [intarray]
        for i, string in enumerate(strs):
            key = "".join(sorted(string))
            if key in strDict:
                strDict[key].append(i)
            else:
                strDict[key] = [i]
        
        ans = []
        for item in strDict:
            temp = []
            for i in strDict[item]:
                temp.append(strs[i])
            ans.append(temp)
        return ans
# assume string length k
# O(nklogk) time, O(nk) space

# cleaner solution: (use defaultdict to avoid checking if key exists)
from typing import List
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list)

        for s in strs:
            key = "".join(sorted(s))
            groups[key].append(s)

        return list(groups.values())
# or not use defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = []

        for s in strs:
            key = "".join(sorted(s))
            if key in groups:
                groups[key].append(s)
            else:
                groups[key] = [s]

        return list(groups.values())