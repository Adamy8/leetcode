#include<vector>
#include<priority_queue>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n <= 1) return intervals;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // min-heap
        for(int i=0; i<n; i++){
            pq.push({intervals[i][0],intervals[i][1]});
        }

        vector<vector<int>> ans;
        auto[ a1, a2 ] = pq.top();
        pq.pop();
        while(pq.size()){
            auto[b1, b2] = pq.top();    // b1 >= a1
            pq.pop();
            if(a2 >= b2){
                // ans.push_back({a1,a2});
                // a1 = a1; a2 = a2; // no update
            }
            else if(a2 >= b1){
                // ans.push_back({a1,b2});
                a1 = a1; a2 = b2;
            }
            else{   // a2 < b1
                ans.push_back({a1,a2});
                a1 = b1; a2 = b2;
            }
            if(pq.size() == 0) ans.push_back({a1,a2});
        }

        return ans;
    }
};