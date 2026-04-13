#include <vector>
// #include <priority_queue>
#include <climits>
class Solution {
public:
    struct worker{
        double wbq;     // wage/quality
        int quality;
        int wage;
    };
    struct cmp{
        bool operator()(const worker& a, const worker& b) const {
            return a.wbq > b.wbq;       // ascending
        }
    };
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<worker> workers(n);
        for(int i=0; i<n; i++){
            workers[i] = {static_cast<double>(wage[i])/quality[i], quality[i], wage[i]};
        }
        sort(workers.begin(), workers.end(), cmp());

        double minCost = INT_MAX, curr;
        for(int i=0; i<=n-k; i++){
            curr = workers[i].wage;
            for(int j=1; j<k; j++){
                curr += (static_cast<double>(workers[i+j].quality) / workers[i].quality) * workers[i].wage;
            }
            minCost = min(minCost, curr);
        }
        return minCost;
    }
};