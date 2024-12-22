class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        library = ['','','abc','def','ghi','jkl','mno','pqrs','tuv','wxyz']
        # letters = []
        # for char in str:
        #     letters.append(library[int(char)])
        
        def backtrack(idx, comb):
            if idx == len(digits):
                res.append(''.join(comb))
                return
            
            letters = library[int(digits[idx])]

            for letter in letters:
                backtrack(idx + 1, comb + letter)

        res = []
        backtrack(0, "")
        return res
