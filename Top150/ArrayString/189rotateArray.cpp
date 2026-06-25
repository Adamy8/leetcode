// extra memory, most direct sol
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        while(nums.size() <= k) k-= nums.size();

        vector<int> temp = nums;
        for(int i=0; i<nums.size(); i++){
            if( i<k ){
                nums[i] = temp[nums.size()-k+i];
            }
            else{
                nums[i] = temp[i-k];
            }
        }
    }
};
// O(n) time, O(n) space

// my method 2: reverse the whole array, then reverse the first k elements, and reverse the rest n-k elements
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        while(n <= k) k-= n;

        for(int i=0; i<n/2; i++){
            swap(nums[i], nums[n-i-1]);
        }
        for(int i=0; i<k/2; i++){
            swap(nums[i], nums[k-i-1]);
        }
        for(int i=k; i< k + (n-k)/2; i++){
            swap(nums[i], nums[n - i + k - 1]);
        }
    }
};
// O(n) time, O(1) space

//damn, clean solution by others: uses reverse func
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

//one more way O(n*k), O(1) space. Repeatly move the last element to the front, k times
//Brute force, not a good one