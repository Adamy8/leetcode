class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:

        # words = []
        # words.entend(list(sentence.split(" ")))
        #// this also works!  Use extend instead of append to avoid nested list
        

        words = sentence.split(" ")
        length = len(searchWord)

        for i in range(len(words)):
            # or you can use the python start with function
            if words[i][0:length] == searchWord :
                return i
        return -1
            
if __name__ == "__main__":
    sol = Solution()
    result = sol.isPrefixOfWord("svsfdsbg csgfw dsfgf dsfgds test v df sgdfdsv", "tes")
    print(result)

