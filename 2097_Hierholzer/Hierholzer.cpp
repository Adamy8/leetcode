#include<iostream>
#include<vector>
#include<map>
using namespace std;
// ^ not needed for leet

class Solution {
public:
    typedef struct{
        vector<int> outedges;
        vector<int> inedges;
    }Node;

    void DFS(int currKey, vector<vector<int> >& solution,map<int, Node>& Graph) {
        Node& at = Graph.at(currKey);

        while(!at.outedges.empty()){
            int nextNodeValue = at.outedges.back();
            at.outedges.pop_back();
            
            Graph[currKey] = at;

            Graph[nextNodeValue].inedges.pop_back();
            // Graph[nextNodeValue].inedges.push_back(currKey);   // trick here: use the unneeded field of Node
            DFS(nextNodeValue, solution, Graph);

            solution.push_back({currKey, nextNodeValue});
        }

        // int preKey = Graph[currKey].inedges.back();
        // if(preKey != -1){
        //     Graph[currKey].inedges.pop_back();
        //     solution.insert(solution.begin(), {preKey, currKey});
        //     if (Graph[currKey].inedges.empty()) {
        //         Graph[currKey].inedges.push_back(-1);
        //     }
        // }
    };

    vector<vector<int> > validArrangement(vector<vector<int> >& pairs) {
        int pairNum = pairs.size();

        map<int,Node> Graph;

        for (int i = 0; i < pairNum; i++) {
            int from = pairs[i][0];
            int to = pairs[i][1];

            // Update node
            Graph[from].outedges.push_back(to);
            Graph[to].inedges.push_back(from);
        }

        int startKey = Graph.begin()->first;
        // Node start = Graph.begin()->second;
        // finding start
        for (map<int, Node>::const_iterator it = Graph.begin(); it != Graph.end(); ++it) {
            int value = it->first;
            const Node& node = it->second;

            if(node.outedges.size() - node.inedges.size() == 1){
                startKey = value;
                break;
            }
        }

        vector<vector<int> > solution;
        DFS(startKey, solution, Graph);
        reverse(solution.begin(), solution.end());  // Reverse the result to get the correct order
        return solution;
    }
};


// for testing only
int main(){
    vector<vector<int> > pairs;
    pairs.push_back({5, 1});
    pairs.push_back({4, 5});
    pairs.push_back({11, 9});
    pairs.push_back({9, 4});

    vector<vector<int> > pairs1;
    pairs1.push_back({1, 2});
    pairs1.push_back({1, 3});
    pairs1.push_back({2, 1});
    vector<vector<int> > pairs2;
    pairs2.push_back({1, 3});
    pairs2.push_back({3, 2});
    pairs2.push_back({2, 1});
    vector<vector<int> > pairs3;
    pairs3.push_back({17, 18});
    pairs3.push_back({18, 10});
    pairs3.push_back({10, 18});


    vector<vector<int> > pairs4;
    pairs4.push_back({8, 5});
    pairs4.push_back({8, 7});
    pairs4.push_back({0, 8});
    pairs4.push_back({0, 5});
    pairs4.push_back({7, 0});
    pairs4.push_back({5, 0});
    pairs4.push_back({0, 7});
    pairs4.push_back({8, 0});
    pairs4.push_back({7, 8});



    Solution sol;
    vector<vector<int> > vec = sol.validArrangement(pairs1);

    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "[" << vec[i][0] << "," << vec[i][1] << "]";
        if (i != vec.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

}