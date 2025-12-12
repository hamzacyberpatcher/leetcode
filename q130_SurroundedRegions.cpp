class Solution {
public:
    void DFS(vector<vector<char>>& board, int i, int j, int m, int n, vector<vector<bool>>& visited)
    {
        board[i][j] = 'T';
        visited[i][j] = true;

        if (i + 1 < n && board[i + 1][j] == 'O' && !visited[i + 1][j])
            DFS(board, i + 1, j, m, n, visited);
        
        if (i - 1 >= 0 && board[i - 1][j] == 'O' && !visited[i - 1][j])
            DFS(board, i - 1, j, m, n, visited);

        if (j + 1 < m && board[i][j + 1] == 'O' && !visited[i][j + 1])
            DFS(board, i, j + 1, m, n, visited);

        if (j - 1 >= 0 && board[i][j - 1] == 'O' && !visited[i][j - 1])
            DFS(board, i, j - 1, m, n, visited);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O')
                DFS(board, 0, j, m, n, visited);
            
            if (board[n - 1][j] == 'O')
                DFS(board, n - 1, j, m, n, visited);
        }

        for(int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
                DFS(board, i, 0, m, n, visited);

            if (board[i][m - 1] == 'O')
                DFS(board, i, m - 1, m, n, visited);
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if (board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }

        
    }
};
