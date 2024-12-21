#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > min_heap;
        for(int i=0;i<nums.size();i++){
            min_heap.push({nums[i],i});
        }
        while(k--){
            auto [val, i] = min_heap.top();  // C++17 structured binding

            min_heap.pop();
            min_heap.push({val*multiplier,i});
        }

        vector<int> result(min_heap.size(), 0);
        int size = min_heap.size();
        for(int i=0;i<size;i++){
            auto [val,index] = min_heap.top();
            min_heap.pop();
            result[index] = val;
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,1,3,5,6};
    int k = 5;
    int multiplier = 2;

    nums = sol.getFinalState(nums,k,multiplier);
    for(const int& num:nums){
        cout<< num<<", ";
    }
    cout<<endl;
    return 0;
}