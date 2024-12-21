import heapq
from typing import List
# ^not needed in leetcode

class Solution:
    directions = [(0,1),(0,-1),(-1,0),(1,0)]

    def printGrid(self,grid,row,col):
        for i in range(row):
            for j in range(col):
                print(grid[i][j],end=" ")
            print()
        print() #"end...\n")
  
    def minimumTime(self, grid: List[List[int]]) -> int:
        def _is_valid(grid, row,col):
            return (0<=row<len(grid)) and (0<=col<len(grid[0]))
        
        R,C = len(grid),len(grid[0])

        min_time = [[float("inf")] * C for _ in range(R)]

        if grid[0][0] != 0: return -1

        min_time[0][0] = grid[0][0]
        pq = [( min_time[0][0], 0,0 )]  #turple: min_time and index of row+col

        while pq:
            self.printGrid(min_time,R,C)  # debug ----------------------- delete this for leet code submission
            curtime, row, col = heapq.heappop(pq)

            if row==R-1 and col==C-1:
                return curtime
            
            curtime += 1

            if grid[0][1] > 1 and grid[1][0] > 1:
                return -1

            for dr,dc in self.directions:
                nR, nC = row + dr, col + dc
                if _is_valid(grid, nR, nC):
                    if curtime >= grid[nR][nC]:
                        newtime = curtime
                    else:
                        difference = grid[nR][nC] - curtime -1
                        if difference % 2 == 0:
                            newtime = grid[nR][nC] + 1
                        else: # difference is odd
                            newtime = grid[nR][nC]

                    if newtime < min_time[nR][nC]:
                        min_time[nR][nC] = newtime
                        heapq.heappush( pq, (newtime, nR, nC) )
        return -1

# for test only
if __name__ == "__main__":
    grid1 = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
    grid2 = [[0,2,4],[3,2,1],[1,0,4]]
    grid3 = [[0,1,99],[3,99,99],[4,5,6]]
    solution = Solution()
    mintime = solution.minimumTime( grid3 )
    print(mintime)