#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> count(32);
        for(int x : nums){
            for(int index=0;index<32;index++){
                if((x>>index) & 1) count[index]+=1;   
            }
        }
        int ans = 0;
        for(int i =0;i<32;i++){
            count[i] %= 3;
            if(count[i]){
                ans |= (1<<i);
            }
        }
        return ans;
    }
};

// O(n) time complexity, O(1) space complexity.

// ans |= (1<<i)   is better than   ans += pow(2,i)