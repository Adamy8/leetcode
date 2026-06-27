class Solution:
    def isValid(self, s: str) -> bool:
        if not s: return True

        stack = []
        for c in s:
            if c in "({[":
                stack.append(c)
            elif not stack:
                return False
            elif c==')' and stack[-1]=='(':
                stack.pop()
            elif c=='}' and stack[-1]=='{':
                stack.pop()
            elif c==']' and stack[-1]=='[':
                stack.pop()
            else:
                return False
        return not stack
# my sol, O(n) time and space

# cleaner python code, same approach:
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        match = {
            ')': '(',
            '}': '{',
            ']': '['
        }

        for c in s:
            if c in "({[":
                stack.append(c)
            else:
                if not stack or stack[-1] != match[c]:
                    return False
                stack.pop()

        return not stack