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
        int leftMax = maxSum(nums, l, mid );
        int rightMax = maxSum(nums, mid+1, r );
        
        int sum=0;
        int midLeft = INT_MIN;
        for(int i=mid; i>=l; i--){
            sum += nums[i];
            midLeft = max(midLeft, sum);
        }
        sum=0;
        int midRight = INT_MIN;
        for(int i=mid+1; i<=r; i++){
            sum += nums[i];
            midRight = max(midRight, sum);
        }
        
        return max(leftMax, max(midLeft+midRight,rightMax));
    }
};