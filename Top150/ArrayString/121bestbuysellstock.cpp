// my solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;

        int curLowest = prices[0];
        int maxProfit = 0;
        for(int price:prices){
            if(price <= curLowest) curLowest = price;
            else maxProfit = max(maxProfit, price-curLowest);
        }
        return maxProfit;
    }
};
// O(n) time and O(1) space

