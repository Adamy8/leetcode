#include <iostream>
#include <queue>
#include<vector>
using namespace std;

class Solution {
private:
    struct Compare{
        bool operator()(const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        }
    };
    void potential_cal(vector<int> &oneClass){
            double pass = oneClass[0];
            double total = oneClass[1];
            
            double potentialGrowth = (pass+1)/(total+1) - pass/total;
            oneClass.push_back(potentialGrowth*100000000);
    }

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        //calculate potential growth:

        priority_queue< vector<int>, vector<vector<int>>, Compare > pq;
        
        for(int i=0; i<size(classes); i++){
            potential_cal(classes[i]);
            pq.push(classes[i]);
        }

        while(extraStudents--){
            vector<int> oneClass = pq.top();
            pq.pop();
            oneClass[0]++;
            oneClass[1]++;

            oneClass.pop_back();
            potential_cal(oneClass);
            pq.push(oneClass);
        }

        double count = 0;
        while(!pq.empty()){
            auto element = pq.top();
            count +=  double(element[0]) / double(element[1]);
            pq.pop();
        }

        return count / size(classes);
    }
};

// not for leet submission
int main(){
    Solution sol;
    // test cases
    vector<vector<int>> classes;
    classes.push_back({2, 4});
    classes.push_back({3, 9});
    classes.push_back({4, 5});
    classes.push_back({2, 10});
    int extraStudents = 4;
    
    cout<< sol.maxAverageRatio(classes,extraStudents) << endl;
    return 0;
}
