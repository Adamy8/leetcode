# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root: return []
        dq = deque([root])

        ans = []
        while dq:
            temp = []
            for _ in range(len(dq)):
                node = dq.popleft()
                temp.append(node.val)
                if node.left:
                    dq.append(node.left)
                if node.right:
                    dq.append(node.right)
            ans.append(temp)
        return ans
# my solution, BFS with deque, O(n) time, O(n) space. 
# queue alone is O(w) space. But we also need to store the answer, so O(n) space in total.
# O(w) in worse case w = n/2 = O(n) in a complete binary tree.


# there's also a recrusive solution, DFS with recursion, O(n) time, O(h) space. h is the height of the tree. In worse case h = n in a skewed tree.

# same for 107, just return ans[::-1] instead