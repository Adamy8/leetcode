// my solution: DP
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> jumpNum(nums.size(), INT_MAX);
        jumpNum[0] = 0;
        for(int i=0; i<nums.size(); i++){
            for(int j=1; j<=nums[i]; j++){
                if(i+j >= nums.size()) continue;
                jumpNum[i+j] = min(jumpNum[i+j],jumpNum[i]+1);
            }
        }
        return jumpNum[nums.size()-1];
    }
};
// worst O(n^2) time (nums=[n,n,n,...n]), O(n) space


//very clever, Greedy solution:
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int currEnd = 0;   // current jump range end
        int maxReach = 0;  // farthest index seen in current range

        // Scan range by range (like BFS levels).
        for (int i = 0; i < n - 1; ++i) {
            // While we are inside current range, keep extending farthest reach.
            maxReach = max(maxReach, i + nums[i]);

            // Only jump when we finish current range.
            if (i == currEnd) {
                ++jumps;
                currEnd = maxReach;

                // Early stop once we can reach the last index.
                if (currEnd >= n - 1) break;
            }
        }

        return jumps;
    }
};
