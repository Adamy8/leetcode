// use struct or tuple
#include<queue>
#include<algorithm>
struct Node{
    int val;
    int x,y;
};
class Solution {
public:
    int maxDepth(const Node& root,vector<vector<int>>& matrix){
        int l = 1, r = 1, u = 1, d = 1;
        if(root.x > 0 && root.val < matrix[root.x-1][root.y]) 
            u = 1 + maxDepth({matrix[root.x-1][root.y], root.x-1, root.y}, matrix);

        if(root.y > 0 && root.val < matrix[root.x][root.y - 1])
            l = 1 + maxDepth({matrix[root.x][root.y-1], root.x, root.y-1}, matrix);

        if(root.x < matrix.size() - 1 && root.val < matrix[root.x+1][root.y])
            d = 1 + maxDepth({matrix[root.x+1][root.y], root.x+1, root.y}, matrix);

        if(root.y < matrix[0].size() - 1 && root.val < matrix[root.x][root.y+1])
            r = 1 + maxDepth({matrix[root.x][root.y+1], root.x, root.y+1}, matrix);
        return max(max(l,r),max(u,d));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(); //row
        int n = matrix[0].size(); //column
        queue<Node> q;
        for(int i=0;i<m; i++){
            for(int j=0; j<n; j++){
                q.push({matrix[i][j],i,j});
            }
        }
        int max = 0, temp;
        while(q.size()!=0){
            temp = maxDepth(q.front(), matrix);
            q.pop();
            if (temp > max) max = temp;
        }
        return max;
    }
};