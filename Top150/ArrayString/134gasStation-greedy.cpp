class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int fuel = 0;
        int start = 0;
        for(int i=0; i<n;i++){
            fuel += gas[i];
            if(fuel<cost[i]){
                start = i+1;
                if(start >= n) return -1;
                fuel = 0;
            }else{
                fuel -= cost[i];
            }
        }
        // if reach here, it's still going
        for(int i=0; i<n;i++){
            fuel += gas[i];
            if(fuel<cost[i]) return -1;
            else{
                if(i==start) return start;
                fuel-=cost[i];
            }
        }
        return -1;
    }
};  
// O(n) time, O(1) space

// Method 2: judge if there's solution first by the total fuel and cost, if yes then only do one pass is good
// python:
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas) < sum(cost):
            return -1
                
        curernt_gas = 0
        start = 0
        for i in range(len(gas)):
            curernt_gas += gas[i] - cost[i]
            if curernt_gas < 0:
                curernt_gas = 0
                start = i + 1

        return start