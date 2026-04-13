#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    struct worker{
        double wbq;
        int quality;
        int wage;
    };

    struct cmp{
        bool operator()(const worker& a, const worker& b) const {
            return a.wbq < b.wbq;       // decending
        }
    };

    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<worker> workers(n);

        for (int i = 0; i < n; i++) {
            workers[i] = {static_cast<double>(wage[i]) / quality[i], quality[i], wage[i]};
        }

        sort(workers.begin(), workers.end(), cmp());

        priority_queue<int> pq;   // max-heap of qualities
        int qsum = 0;
        double minCost = DBL_MAX;

        for (int i = 0; i < n; i++) {
            pq.push(workers[i].quality);
            qsum += workers[i].quality;

            if (pq.size() > k) {
                qsum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                minCost = min(minCost, qsum * workers[i].wbq);
            }
        }

        return minCost;
    }
};