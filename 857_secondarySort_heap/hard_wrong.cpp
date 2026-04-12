#include <vector>
#include <priority_queue>
class Solution {
public:
    struct worker{
        double wbq;
        int quality;
        int wage;
    }
    struct cmp {
        bool operator()(const worker& a, const worker& b) const {
            return a.wbq > b.wbq;               // min heap
        }
    };
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        priority_queue<worker, vector<worker>, cmp> pq;
        for(int i=0; i<n; i++){
            pq.push({wage[i]/quality[i], quality[i], wage[i]});
        }
        // realise i need vector here, restart
        
    }
};