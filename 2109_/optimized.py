class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        result = []
        result.append( s[ 0:spaces[0] ] )
    
        for i in range(len(spaces)-1):
            result.append(s[ spaces[i] : spaces[i+1] ])
            
        result.append( s[ spaces[len(spaces)-1] : len(s) ] )
        return ' '.join(result)
