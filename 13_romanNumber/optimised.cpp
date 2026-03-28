#include <unordered_map>
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> roman ={
            {'I',1}, {'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int result = roman[s[0]];
        for(int i=1; i<s.size(); i++){
            result += roman[s[i]];
            if(roman[s[i-1]] < roman[s[i]]) result-=(2 * roman[s[i-1]]);
        }
        
        return result;
    }
};