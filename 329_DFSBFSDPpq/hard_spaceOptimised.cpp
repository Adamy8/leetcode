// use struct or tuple
#include<queue>
#include<algorithm>
struct Node{
    int val;      // val is not really needed
    int x,y;
};
class Solution {
public:
    int maxDepth(const Node& root,vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if (dp[root.x][root.y]) return dp[root.x][root.y];

        int m = matrix.size();
        int n = matrix[0].size();
        int val = matrix[root.x][root.y];

        int l = 1, r = 1, u = 1, d = 1;

        if (root.x > 0 && val < matrix[root.x - 1][root.y])
            u = 1 + maxDepth({matrix[root.x - 1][root.y], root.x-1, root.y}, matrix, dp);
        if (root.y > 0 && val < matrix[root.x][root.y - 1])
            l = 1 + maxDepth({matrix[root.x][root.y - 1], root.x, root.y-1}, matrix, dp);
        if (root.x < m - 1 && val < matrix[root.x + 1][root.y])
            d = 1 + maxDepth({matrix[root.x + 1][root.y], root.x+1, root.y}, matrix, dp);
        if (root.y < n - 1 && val < matrix[root.x][root.y + 1])
            r = 1 + maxDepth({matrix[root.x][root.y+1], root.x, root.y + 1}, matrix, dp);

        int ans = max(max(l,r),max(u,d));
        dp[root.x][root.y] = ans;
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(); //row
        int n = matrix[0].size(); //column

        int max = 0, temp;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0;i<m; i++){
            for(int j=0; j<n; j++){
                temp = maxDepth({matrix[i][j],i,j}, matrix, dp);
                if (temp > max) max = temp;
            }
        }
        return max;
    }
};