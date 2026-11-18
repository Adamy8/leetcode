// O(n^2) O(n^2) DP solution
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp( triangle.size() , vector<int>(triangle.size(), INT_MAX) );
        return DPtree(triangle, 1, 0, dp) + triangle[0][0];
        
    }
    int DPtree(vector<vector<int>>& triangle, int level, int left, vector<vector<int>>& dp){     // right = left + 1
        if(level == triangle.size()) return 0;
        if(dp[level][left] != INT_MAX) return dp[level][left];

        if(level == triangle.size()-1){
            int ans = min(triangle[level][left], triangle[level][left+1]);
            dp[level][left] = ans;
            return ans;
        }

        int ans = min(DPtree(triangle, level+1, left, dp) + triangle[level][left], 
                    DPtree(triangle, level+1, left+1, dp) + triangle[level][left+1] );
        dp[level][left] = ans;
        return ans;
    }
};
// better one: bottom up solution
