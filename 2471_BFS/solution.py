# min swaps required to make arr1 equal to arr2

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countSwap(self,level):
        count = 0
        sortedLevel = sorted(level)
        for i in range(len(level)):
            if sortedLevel[i] == level[i]:
                continue
            idx = level.index(sortedLevel[i])
            level[i],level[idx] = level[idx],level[i]
            count += 1
        return count

    def BFS(self, root):
        if not root:
            return []
        
        queue = deque([root])
        result = []
        
        while queue:
            level_size = len(queue)
            current_level = []
            
            for _ in range(level_size):
                node = queue.popleft()
                current_level.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            result.append(current_level)

        return result

    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        levels = self.BFS(root)
        total_swaps = 0
        
        # For each level, find the minimum swaps to sort the level
        for level in levels:
            total_swaps += self.countSwap(level)
        
        return total_swaps
