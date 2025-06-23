
// 这是个笨办法，暴力破解。有聪明很多的方法。

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int minlength = min(str1.length(),str2.length());

        int sameuntil = -1;
        for(int i=0; i< minlength; i++){
            if(str1[i] == str2[i]){
                sameuntil = i;
            }
            else{
                break;
            }
        }
        int gcd = sameuntil+1;
        if(!gcd) return "";
        while(true){
            string gcdstr = str1.substr(0, gcd);
            if(isconsist(str1,gcdstr) && isconsist(str2,gcdstr)){
                return gcdstr;
            }
            gcd -= 1;
            if (gcd == 0) return "";
        }
    }

    bool isconsist(string str, string gcdstr){
        int len = gcdstr.length();
        if(str.length() % len != 0) return false;
        string repeated = "";
        for(int i=0; i< str.length()/len; i++){
            repeated += gcdstr;
        }
        return repeated == str;
    }
};


int main() {
    Solution sol;
    string str1 = "ABCABC";
    string str2 = "ABC";
    cout << sol.gcdOfStrings(str1, str2) << endl; // Output: "ABC"

    str1 = "ABABAB";
    str2 = "ABAB";
    cout << sol.gcdOfStrings(str1, str2) << endl; // Output: "AB"

    str1 = "LEET";
    str2 = "CODE";
    cout << sol.gcdOfStrings(str1, str2) << endl; // Output: ""

    str1 = "AA";
    str2 = "A";
    cout << sol.gcdOfStrings(str1, str2) << endl; // Output: "A"

    return 0;
}