#include <string>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int i=0;
        while(i < strs[0].size()){
            char temp = strs[0][i];
            for(int j=1; j<strs.size(); j++){
                if( i>=strs[j].size()  ||  strs[j][i] != temp) return ans;
            }
            ans += temp;
            i++;
        }
        return ans;
    }
};