class Solution {
public:

    int countAlive(vector<vector<int>>& board, int r, int c)
    {
        int rows = board.size();
        int cols = board[0].size();

        int count = 0;

        for(int i = r - 1; i <= r + 1; i++)
        {
            for(int j = c - 1; j <= c + 1; j++)
            {
                if(i == r && j == c)
                    continue;
                
                if (i < 0 || i >= rows || j < 0 || j >= cols)
                    continue;
                
                if (board[i][j]) count++;
            }
        }

        return count;
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int, int>> die;
        vector<pair<int, int>> born;

        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                int count = countAlive(board, i, j);

                if (count < 2 || count > 3)
                    die.push_back(make_pair(i, j));
                
                if (count == 3)
                    born.push_back(make_pair(i, j));
            }
        }

        for(const auto & p : die)
            board[p.first][p.second] = 0;
        
        for(const auto & p : born)
            board[p.first][p.second] = 1;
    }
};
