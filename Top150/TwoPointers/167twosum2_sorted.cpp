// i assumed it's not sorted in the input, but it actually is, so my prev submission is better down
// there w O(1) space
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        unordered_map<int, size_t> valtoloc;
        for(size_t i = 0; i < numbers.size(); i++){
            if(valtoloc.find(target - numbers[i]) != valtoloc.end()){
                ans.push_back(valtoloc[target - numbers[i]] + 1);
                ans.push_back(i + 1);
                return ans;
            }
            valtoloc[numbers[i]] = i;
        }
        return ans;
    }
};

// O(1)space
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int a=0, b=numbers.size()-1;
        while(a<b){
            if(numbers[a]+numbers[b]==target) return{a+1,b+1};
            else if(numbers[a]+numbers[b]<target) a++;
            else b--;
        }
        return {};
    }
};