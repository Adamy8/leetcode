// use struct or tuple
// #include<queue
// struct Node{
//     int val;
//     int x,y;
// }
#include<tuple>
#include<priority_queue>
#include<vector>
#include<queue>
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;
        int m = matrix.size(); //row
        int n = matrix[0].size(); //column
        for(int i=0;i<m; i++){
            for(int j=0; j<n; j++){
                pq.push({matrix[m][n], m, n});
            }
        }

        while(pq.size()!=0){
            auto [val, x, y] = pq.top();
            pq.pop();
            // this is to order elements, getting min first;
            // but i just realized there's no need to order em, so restart
        }
    }
};