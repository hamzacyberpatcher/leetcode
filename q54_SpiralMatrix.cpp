class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0;
        int right = cols - 1;

        int top = 0;
        int bottom = rows - 1;

        vector<int> vec;

        int i = 0;

        while (i < rows * cols)
        {
            for(int k = left; k <= right && i < rows * cols; k++, i++) vec.push_back(matrix[top][k]);
            top++;

            for(int k = top; k <= bottom && i < rows * cols; k++, i++) vec.push_back(matrix[k][right]);
            right--;

            for(int k = right; k >= left && i < rows * cols; k--, i++) vec.push_back(matrix[bottom][k]);
            bottom--;

            for(int k = bottom; k >= top && i < rows * cols; k--, i++) vec.push_back(matrix[k][left]);
            left++;
        }

        return vec;
    }
};
