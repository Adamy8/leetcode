# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root: return 0
        def DP(root, curDepth:int) -> int:
            if not root.left and not root.right: return curDepth
            temp = 0
            if root.left:
                temp = DP(root.left, curDepth+1)
            if root.right:
                temp = max(temp, DP(root.right,curDepth+1))
            return temp
        return DP(root,1)
# DP solution, O(n) time, O(h) space where h is the height of the tree

# damn cleaner version:  bottom up
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return 1 + max(
            self.maxDepth(root.left),
            self.maxDepth(root.right)
        )

# or BFS with deque: O(n) time, O(w) space, w is width of tree, worst case O(n/2) = O(n)
from collections import deque
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root: return 0
        dq = deque([root])
        depth = 0
        while dq:
            depth+=1
            for _ in range(len(dq)):
                node = dq.popleft()
                if node.left: dq.append(node.left)
                if node.right: dq.append(node.right)
        return depth

# or DFS with stack: O(n) time, O(h) space, h is height of tree, worst case O(n)
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        stack = [(root, 1)]

        ans = 0
        while stack:
            node, depth = stack.pop()
            ans = max(ans, depth)
            if node.left:
                stack.append((node.left, depth + 1))
            if node.right:
                stack.append((node.right, depth + 1))
        return ans