#include<iostream>
#include<vector>

class Solution {
private:
    typedef struct node_struct{
        int value = -1;
        int left = -1;
        int right = -1;
    }Node;

    int DFS(vector<Node> tree, vector<int> & sum, int curr){
        if (tree[curr].left == -1 && tree[curr].right == -1){
            sum[curr] = tree[curr].value;
        }elif(tree[curr].left == -1){
            sum[curr] = tree[curr].value + DFS(tree,sum,tree[curr].right);
        }elif(tree[curr].right == -1){
            sum[curr] = tree[curr].value + DFS(tree,sum,tree[curr].left);
        }else{
            sum[curr] = tree[curr].value + DFS(tree,sum,tree[curr].left) + DFS(tree,sum,tree[curr].right);
        }
        return sum[curr];
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<Node> tree;
        for(int i =0; i< n;i++){
            Node node;
            node.value = values[i];
            tree.pushback(node);
        }
        for(auto[a,b] : edges){
            if(tree[a].left == -1){
                tree[a].left = b;
            }else{
                tree[a].right = b;
            }
        }
        vector<int> Sums(n);
        DFS(tree,Sums,0);
        
    
    }
};