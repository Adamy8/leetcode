class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int all = 1, n=nums.size();
        int zeroLoc = -1;
        vector<int> res(n,0);
        for(int i=0; i<n; i++){
            if(!nums[i]){
                if(zeroLoc != -1) return res;
                zeroLoc = i;
            }else{
                all *= nums[i];
            }
        }
        if(zeroLoc != -1){      // should only have one 0 if reach here
            res[zeroLoc] = all;
            return res;
        }
        for(int i=0; i<n; i++){
            res[i] = all / nums[i];
        }
        return res;
    }
};
// just learnd this in 281 lol
// O(n) time
// O(n) space for return

// Method 2, keep track of left and right:
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 1);

        int left = 1;
        for (int i = 0; i < nums.size(); i++) {
            output[i] *= left;
            left *= nums[i];
        }

        int right = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            output[i] *= right;
            right *= nums[i];
        }

        return output;        
    }
};