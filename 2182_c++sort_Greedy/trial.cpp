#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
private:
    struct Compare{
        bool operator()(const pair<char,int>& a, const pair<char,int>& b){
            // return a.first < b.first;  //max-heap on char, this is for make_heap
            return a.first > b.first;  //this is max-heap for sort
        }
    };
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char,int> letters;
        for(char ch: s){
            letters[ch]++;
        }

        vector<pair<char, int>> heapVec(letters.begin(), letters.end());
        // make_heap(heapVec.begin(), heapVec.end(), Compare());            //!!!! make_heap only make sure the first element is the largest
        sort(heapVec.begin(), heapVec.end(), Compare()); 

        string str = "";
        
        for(int i=0; i<heapVec.size(); i++){
            char ch = heapVec[i].first;
            int* num = &(heapVec[i].second);
            while(*num > repeatLimit){
                str.append(repeatLimit, ch);
                *num -= repeatLimit;

                // find ch to plug in
                int cur = i;
                do{
                    if(cur == heapVec.size()-1){
                        return str;
                    }
                    cur += 1;
                }while(heapVec[cur].second == 0);

                str += heapVec[cur].first;
                heapVec[cur].second --;
            }
            str.append(*num, ch);
        }
        return str;
    }
};

// not for leet
int main(){
    // string s = "aababab";
    // int limit = 2;
    // string s = "cczazcc";
    // int limit = 3;
    string s = "pdprlxqryxdirdr";
    int limit = 10;

    Solution sol;
    cout<<sol.repeatLimitedString(s,limit)<<endl;
}