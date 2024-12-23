#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    typedef struct node_struct{
        int value = -1;
        vector<int> children;
        int left = -1;
        int right = -1;
    }Node;

    int DFS(vector<Node> tree, vector<int> & sum, int curr){
        if (tree[curr].left == -1 && tree[curr].right == -1){
            sum[curr] = tree[curr].value;
        }else if(tree[curr].left == -1){
            sum[curr] = tree[curr].value + DFS(tree,sum,tree[curr].right);
        }else if(tree[curr].right == -1){
            sum[curr] = tree[curr].value + DFS(tree,sum,tree[curr].left);
        }else{
            sum[curr] = tree[curr].value + DFS(tree,sum,tree[curr].left) + DFS(tree,sum,tree[curr].right);
        }
        return sum[curr];
    }
    bool is_in(const vector<int> arr, int n){
        return find(arr.begin(), arr.end(), n) != arr.end();
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<Node> tree;
        for(int i =0; i< n;i++){
            Node node;
            node.value = values[i];
            tree.push_back(node);
        }

        vector<bool> flags(n,true);
        vector<int> HasParents;

        for(auto element : edges){
            int a = element[0];
            int b = element[1];
            if(is_in(HasParents,b)){
                int temp = a;
                a = b;
                b = temp;
            }
            flags[b] = false;
            HasParents.push_back(b);

            tree[a].children.push_back(b);
            //     tree[a].left = b;
            // }else{
            //     tree[a].right = b;
            // }
        }

        int root = 0;
        for(int i=0; i<n;i++){
            if(flags[i]){
                root = i;
                break;
            }
        }

        vector<int> Sums(n);
        DFS(tree,Sums,root);

        int count = 0;
        for(int i=0;i<n;i++){
            if (Sums[i] % k == 0){
                count++;
            }
        }

        return count;
    }
};



int main(){

    // int n = 5;
    // vector<vector<int>> edges = {{0,2},{1,2},{1,3},{2,4}};
    // vector<int> values = {1,8,1,4,4};
    // int k = 6;
    int n = 1;
    vector<vector<int>> edges = {};
    vector<int> values = {10000};
    int k = 100;

    Solution sol;
    cout<<sol.maxKDivisibleComponents(n,edges,values,k)<<endl;
    
    return 0;
}