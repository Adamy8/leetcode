// my solution, same idea w 26,27, two pointers
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;

        int i = 0; // index
        int curCount = 1;
        for(int j=1; j< nums.size(); j++){
            if(nums[j]==nums[i]){
                if(curCount < 2){
                    i++;
                    nums[i] = nums[j];
                }
                curCount++;
            } else { // new item
                curCount = 1;
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
// O(n) time, O(1) space

// use unordered map: (shorter code but O(n) space)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> count;
        int k = 0;

        for (int num : nums) {
            count[num]++;
            if (count[num] <= 2) {
                nums[k] = num;
                k++;
            }
        }

        return k;      
    }
};

// very clever method: use the fact that the array is sorted, so we only need to compare with the element 2 positions before the current position
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2;

        if (nums.size() <= 2) return nums.size();
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;       
    }
};