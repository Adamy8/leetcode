#include<cmath>
#include <climits>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSum(nums,0,nums.size()-1);
    }

    int maxSum(vector<int>& nums, int l, int r){
        if(l>r) return INT_MIN;
        if(l==r) return nums[l];
        int mid = l + (r-l) / 2;
        int leftMax = maxSum(nums, l, mid-1 );
        int rightMax = maxSum(nums, mid+1, r );
        int midMax = nums[mid];
        int i=0;
        while( (mid-(++i)>=l) && nums[mid-i]>=0){           // incorrect midMax logic
            midMax += nums[mid-i];
        }
        i = 0;
        while((mid+(++i)<=r) && nums[mid+i]>=0){
            midMax += nums[mid+i];
        }
        return max(leftMax, max(midMax,rightMax));
    }
};