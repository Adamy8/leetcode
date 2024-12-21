class Solution:
    def existThrice(self,s:str,subs:str):
        # print("s:",s,", subs:",subs)
        count = 0
        for i in range( len(s)-len(subs) +1 ):
            if s[i : i+len(subs)] == subs:
                count += 1
        return count >= 3
    def onlyoneletter(self,s):
        ch = s[0]
        for i in range(len(s)):
            if s[i] != ch:
                return False
        return True
    def maximumLength(self, s: str) -> int:
        for i in range(len(s) -2 ,0,-1):   # i is length of subs
            for j in range(0,len(s) - i +1 ):
                subs = s[j:j+i]
                if self.onlyoneletter(subs) and self.existThrice(s,subs):
                    # print(i)
                    return i
        return -1

# test cases
sol = Solution()

# s = 'aaaa'
s = "cccerrrecdcdccedecdcccddeeeddcdcddedccdceeedccecde"

print(sol.maximumLength(s))