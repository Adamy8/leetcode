#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    struct Node{
        vector<int> links;
    };

    void readInTree(const vector<vector<int>> edges, map<int,Node> * Tree){
        for(auto element : edges){
            int a = element[0];
            int b = element[1];
            (*Tree)[a].links.push_back(b);
            (*Tree)[b].links.push_back(a);
        }
    }

    int shortestMaxLen( const map<int,Node> & Tree , int * maxDiameter){
        if(Tree.empty()) return 0;
        int min = INT_MAX;
        int temp;
        for(auto [idx, node] : Tree){
            temp = maxLen(Tree, idx, node, -1);
            min = (temp < min) ? temp : min ;
            *maxDiameter = (temp > (*maxDiameter)) ? temp : *maxDiameter ;
        }
        return min;
    }

    // DFS in essence
    int maxLen(const map<int,Node>& Tree,int rootIdx, Node root, int parent){
        int max = -1;
        int temp;
        for(auto idx : root.links){
            if(idx == parent) continue;
            temp = maxLen(Tree, idx, Tree.find(idx)->second, rootIdx);
            max = (temp > max) ? temp : max;
        }
        return 1 + max;  // if empty, max = -1 and it happen to add up to 0 with 1 + max
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        map<int,Node> Tree1;
        map<int,Node> Tree2;
        
        readInTree(edges1,&Tree1);
        readInTree(edges2,&Tree2);

        int tree1Max = 0;
        int tree2Max = 0;

        return max(shortestMaxLen(Tree1, &tree1Max) + 1 + shortestMaxLen(Tree2, &tree2Max), max(tree1Max, tree2Max));
    }
};

int main(){
    
    // vector<vector<int>> edges1 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};
    // vector<vector<int>> edges2 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};
    
    // vector<vector<int>> edges1 = {};
    // vector<vector<int>> edges2 = {};
    
    // tricky case, original diameter is longer...
    vector<vector<int>> edges1 = {{0,1},{2,0},{3,2},{3,6},{8,7},{4,8},{5,4},{3,5},{3,9}};
    vector<vector<int>> edges2 = {{0,1},{0,2},{0,3}};

    Solution sol;
    cout<< sol.minimumDiameterAfterMerge(edges1,edges2) << endl;

    return 0;
}