class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();  // row, 3 in ex2
        vector<int> ans;
        if(!m) return ans;
        int n = matrix[0].size();   // col, 4 in ex2

        int left = 0, top = 0;  //they store the available boundary
        int right = matrix[0].size()-1, down = matrix.size()-1;

        for(int i=0; i<m*n; ){
            // add in order or top-right-down-left
            if(top <= down){ // top
                for(int j = left; j <= right; j++){
                    ans.push_back(matrix[top][j]);
                    i++;
                }
                top++;
            }
            if(left <= right){ // right
                for(int j = top; j <= down; j++){
                    ans.push_back(matrix[j][right]);
                    i++;
                }
                right--;
            }
            if(top <= down){ // down
                for(int j = right; j >= left; j--){
                    ans.push_back(matrix[down][j]);
                    i++;
                }
                down--;
            }
            if(left <= right){ // left
                for(int j = down; j >= top; j--){
                    ans.push_back(matrix[j][left]);
                    i++;
                }
                left++;
            }
        }
        return ans;
    }
};