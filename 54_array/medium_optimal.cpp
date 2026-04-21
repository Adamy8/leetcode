class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();

        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;

        while (left <= right && top <= bottom) {
            // top row
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;

            // right column
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // bottom row
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            // left column
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};