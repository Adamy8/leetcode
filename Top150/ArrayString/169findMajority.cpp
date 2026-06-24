// Brute Force(hash map), O(n) time, O(n) space
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int num : nums){
            count[num]++;
            if (count[num] > nums.size()/2) return num;
        }

        return 0; //theoretically, it would never reach here
    }
};

//sort & get medium, O(nlogn) time, O(1) space
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};


// O(n) time, O(1) space, Boyer-Moore Voting Algorithm
class Solution {
public:    
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
// HOLY, 消消乐简直。不一样的就一起消了，然后剩的肯定大于一半了。
