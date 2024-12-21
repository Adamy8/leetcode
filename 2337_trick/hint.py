class Solution:
    def canChange(self, start: str, target: str) -> bool:
        # i,j = 0,0
        star = [[], []]
        targ = [[], []]
        for i in range(len(start)):
            if start[i] != '_':
                star[0].append(start[i])
                star[1].append(i)
            if target[i] != '_':
                targ[0].append(target[i])
                targ[1].append(i)
        if star[0] != targ[0]:
            return False
        for i in range(len(star[0])):
            if star[0][i] == 'L':
                if(star[1][i] < targ[1][i]):
                    return False
            else: # star[i] == 'R'
                if(star[1][i] > targ[1][i]):
                    return False

        return True