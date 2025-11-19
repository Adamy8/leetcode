# // 790
# // Domino and Tromino Tiling
# // Hard AF

MOD = 10**9 + 7

class Solution:
    def numTilings(self, n: int) -> int:
        w = [0,0,0,0]  # a, b, c, d
        