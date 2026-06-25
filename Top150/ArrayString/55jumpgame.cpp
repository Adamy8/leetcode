//my solution, keep track of the last reachable reversely
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return true;

        int lastTrue = n-1 ;
        for(int i=n-2; i>=0; i--){
            if(i+nums[i] >= lastTrue){
                lastTrue = i;
            }
        }
        return lastTrue==0;
    }
};
// O(n) time, O(1) space

// greedy这里竟然能用
int maxReach = 0;
for(int i=0; i<nums.size(); i++){
    if(i>maxReach) return false;
    maxReach = max(maxReach, i+nums[i]);
}
return true;