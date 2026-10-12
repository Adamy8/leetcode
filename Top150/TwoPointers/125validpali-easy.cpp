#include<vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> myv;
        for(int i = 0; i< s.length(); i++){
            char c = tolower(s[i]);
            if('a' <= c && c <= 'z' || '0' <= c && c <= '9'){
                myv.push_back(c);
            }
        }

        for(int i = 0; i< myv.size()/2; ++i){
            if(myv[i] != myv[myv.size()-i-1]) return false;
        }
        
        return true;
    }
};