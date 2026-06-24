// my solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0; // edge case, lwk never happened in test cases

        int i=0; // num of identical items -1
        for(int j=1; j<nums.size(); j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
// similar to 27, two pointers
// O(n) time, O(1) space

