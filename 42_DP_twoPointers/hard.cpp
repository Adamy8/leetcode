#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmax(n,0);
        vector<int> rightmax(n,0);
        int lmax=0, rmax=0;
        for(int i=0; i<n-1; i++){
            if(height[i] > lmax) lmax = height[i];
            if(height[n-i-1] > rmax) rmax = height[n-i-1];
            leftmax[i] = lmax;
            rightmax[n-i-1] = rmax;
        }
        int ans = 0;
        for(int i=1; i<n-1; i++){
            ans += max( min(leftmax[i-1],rightmax[i+1]) - height[i] , 0);
        }
        return ans;
    }
};
