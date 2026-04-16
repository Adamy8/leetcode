class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(! nums.size()) return ans;

        int start = 0,end = 0, curr = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] - 1 == curr){
                curr = nums[i];
                end++;
            }
            else{
                if (start != end)
                    ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
                else
                    ans.push_back(to_string(nums[start]));
                start = i;
                end = i;
                curr = nums[start];
            }
        }
        if (start != end)
            ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
        else
            ans.push_back(to_string(nums[start]));
        return ans;
    }
};
