#include<vector>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> profit(n);
        int max_profit = 0;
        int min = prices[0];
        for(int i=1; i<n;i++){
            if(prices[i] > min){
                profit[i] = prices[i] - min;
                if(profit[i] > max_profit) max_profit = profit[i];
            }
            else if(prices[i] < min) min = prices[i];
        }

        return max_profit;
    }
};