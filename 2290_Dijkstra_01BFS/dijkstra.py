import heapq
from typing import List
# ^not needed in leetcode

class Solution:

    directions = [(0,1),(0,-1),(1,0),(-1,0)]

    def minimumObstacles(self, grid: List[List[int]]) -> int:
        def _is_valid(row,col):
            return 0 <= row < len(grid) and 0 <= col < len(grid[0])
        
        m,n = len(grid),len(grid[0])

        # same to dist()
        min_obstacles = [ [float("inf")] * n for _ in range(m) ]    # float("inf") is infinity in python, here initialized every item to infinity
 
        min_obstacles[0][0] = grid[0][0]

        pq = [ (min_obstacles[0][0], 0, 0) ]

        while pq:    # runs as long as pq is not empty
            obstacles, row, col = heapq.heappop(pq)

            if row == m-1 and col == n-1:
                return obstacles
            for dr,dc in self.directions:
                new_row, new_col = row + dr, col + dc

                if _is_valid(new_row, new_col):
                    new_obstacles = obstacles + grid[new_row][new_col];

                    if new_obstacles < min_obstacles[new_row][new_col]:
                        min_obstacles[new_row][new_col] = new_obstacles
                        heapq.heappush(pq, (new_obstacles, new_row, new_col))
        
        return min_obstacles[m-1][n-1]
