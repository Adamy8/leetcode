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

    int shortestMaxLen( const map<int,Node> & Tree ){
        int min = INT_MAX;
        int temp;
        for(auto [idx, node] : Tree){
            temp = maxLen(Tree, idx, node, -1);
            min = (temp < min) ? temp : min ;
        }
        return min;
    }

    // DFS in essence
    int maxLen(const map<int,Node>& Tree,int rootIdx, Node root, int parent){
        int max = -1;
        int temp;
        for(auto idx : root.links){
            if(idx == parent) continue;
            temp = maxLen(Tree, idx, Tree[idx], rootIdx);
            max = (temp > max) ? temp : max;
        }
        return 1 + max;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        map<int,Node> Tree1;
        map<int,Node> Tree2;
        
        readInTree(edges1,&Tree1);
        readInTree(edges2,&Tree2);

        return shortestMaxLen(Tree1) + 1 + shortestMaxLen(Tree2);
    }
};

int main(){
    
    vector<vector<int>> edges1 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};
    vector<vector<int>> edges2 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};

    Solution sol;
    cout<< sol.minimumDiameterAfterMerge(edges1,edge2) << endl;

    return 0;
}