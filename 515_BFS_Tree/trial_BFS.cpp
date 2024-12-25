/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    
    void BFS(queue<TreeNode*> & curLevel, vector<int> &res){         //C++传址不需要*，用&就行
        while(!curLevel.empty()){
            int max = INT_MIN;
            int curlevelsize = curLevel.size();
            for(int i=0; i<curlevelsize; i++){
                TreeNode* temp = curLevel.front();
                curLevel.pop();
                max = (temp->val > max) ? temp->val : max;
                
                if(temp->left) curLevel.push(temp->left);
                if(temp->right) curLevel.push(temp->right);
            }
            res.push_back(max);
        }
    }

public:
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) return {};              // in C, here should use NULL,  in C++ use nullptr

        vector<int> result;
        queue<TreeNode*> curLevel;
        curLevel.push(root);

        BFS(curLevel, result);

        return result;
    }
};