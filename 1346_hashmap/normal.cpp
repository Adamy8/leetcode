#include <vector>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        vector<int> arr2;
        for(auto& num : arr){
            arr2.push_back(num*2);
        }
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr.size();j++){
                if(i==j)continue;
                if(arr[i]==arr2[j]) return true;
            }
        }
        return false;
    }
};