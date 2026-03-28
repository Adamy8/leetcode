class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()==0) return {};
        if(nums.size()==1) return nums;
        vector<int> leftproduct = nums;
        vector<int> rightproduct = nums;
        for(int i=1; i<nums.size(); i++){
            leftproduct[i] *= leftproduct[i-1];
            rightproduct[nums.size()-i-1] *= rightproduct[nums.size()-i];
        }
        vector<int> answer(nums.size());
        answer[0] = rightproduct[1];
        answer[nums.size()-1] = leftproduct[nums.size()-2];
        for(int i=1; i<nums.size()-1; i++){
            answer[i] = leftproduct[i-1] * rightproduct[i+1];
        }
        return answer;
    }
};