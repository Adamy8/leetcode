// my stupid overcomplicated solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        function<int(int,int,int)> dp = [&](int buyin, int curProfit, int curIndex){
            // return maxProfit
            if(curIndex == prices.size()-1 && buyin != -1){
                return curProfit + max(0,prices[curIndex]-buyin);
            }
            if(curIndex >= prices.size()-1) return curProfit;

            if(prices[curIndex] < buyin || buyin==-1){
                buyin = prices[curIndex];
                return dp(buyin,curProfit,curIndex+1);
            }
            return max(dp(buyin,curProfit,curIndex+1),
                    dp(-1,curProfit + prices[curIndex]-buyin,curIndex+1), )
        }
        return dp(-1,0,0);
    }
};
// O(2^n) time and O(n) space

// gpt improved dp solution: (with memo table)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));

        function<int(int, int)> dp = [&](int i, int holding) -> int {
            if (i == n) return 0;

            if (memo[i][holding] != -1) return memo[i][holding];

            if (holding == 0) {
                return memo[i][holding] = max(
                    dp(i + 1, 0),
                    -prices[i] + dp(i + 1, 1)
                );
            } else {
                return memo[i][holding] = max(
                    dp(i + 1, 1),
                    prices[i] + dp(i + 1, 0)
                );
            }
        };

        return dp(0, 0);
    }
};

//格局大开solution:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};
// O(n) time and O(1) space