class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> cols;
        vector<int> rows;

        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        for(int i = 0; i < rows.size(); i++)
        {
            int row = rows[i];

            for(int j = 0; j < matrix[row].size(); j++)
                matrix[row][j] = 0;
        }

        for(int i = 0; i < cols.size(); i++)
        {
            int col = cols[i];

            for(int j = 0; j < matrix.size(); j++)
                matrix[j][col] = 0;
        }
    }
};
