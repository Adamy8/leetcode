class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid: return 0
        m, n = len(grid), len(grid[0])
        
        def DFS(x,y):
            if x<0 or y<0 or x>=m or y>=n: return
            if (x,y) in visited or grid[x][y] == "0": return
            visited.add((x,y))
            DFS(x+1,y)
            DFS(x-1,y)
            DFS(x,y+1)
            DFS(x,y-1)

        island = 0
        visited = set()
        for x in range(m):
            for y in range(n):
                if (x,y) in visited: continue
                if grid[x][y]=="1": 
                    island += 1
                    DFS(x,y)
                visited.add(( x, y))
        return island
# my sol, DFS but i didnt use stack, used recursion. O(m*n) time, O(m*n) space for visited set.

# also solvable with BFS, using queue. O(m*n) time, O(min(m,n)) space for queue.

# also union find works:
# Every land cell starts as its own island.
# Merge neighboring land cells.
# Count how many groups remain.
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        rows, cols = len(grid), len(grid[0])

        parent = {}
        count = 0

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1":
                    idx = r * cols + c
                    parent[idx] = idx
                    count += 1

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(a, b):
            nonlocal count

            ra = find(a)
            rb = find(b)

            if ra != rb:
                parent[ra] = rb
                count -= 1

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1":
                    curr = r * cols + c

                    if r + 1 < rows and grid[r+1][c] == "1":
                        union(curr, (r+1)*cols + c)

                    if c + 1 < cols and grid[r][c+1] == "1":
                        union(curr, r*cols + c+1)

        return count
# O(m*n) time, O(m*n) space for parent dict.

# For Number of Islands, DFS is usually simpler and preferred.
# Union Find becomes really useful when the grid is changing dynamically.
