class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t i=0,j=0;
        while(i<s.size() && j<t.size()){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else j++;
        }
        return i == s.size();
    }
};

//lwk done it before