//my solution
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0, j=nums.size()-1;
        while(i <= j){
            if(nums[i] == val){
                while(nums[j]==val && i < j) j--;
                if(nums[j]==val) return j;
                nums[i] = nums[j]; j--;
            }
            i++;
        }
        return j+1;
    }
};
// uses two pointers, time complexity O(n), space complexity O(1)

//advanced solution: (way shorter)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        for(int j=0; j<nums.size(); j++){
            if(nums[j] != val){
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};
// uses two pointers, time complexity O(n), space complexity O(1)