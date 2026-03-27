#include<algorithm> // for min, max
class Solution {
public:
    int maxArea(vector<int>& height) {
        int L=0, R=height.size()-1;
        int width = R-L;
        int maxA = min(height[L],height[R]) * width;
        while(R>L){
            if(height[L]<height[R]){
                L++;
            }else R--;
            width--;
            maxA = max(min(height[L],height[R]) * width, maxA);
        }
        return maxA;
    }
}; 

// 11. most water container