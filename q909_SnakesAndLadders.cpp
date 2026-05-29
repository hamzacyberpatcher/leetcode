class Solution {
public:
    pair<int,int> squareToCords(int square, int n)
    {
        int rowFromBottom = (square - 1) / n;
        int row = (n - 1) - rowFromBottom;
        
        int col = (square - 1) % n;
        
        if (rowFromBottom % 2 != 0) {
            col = (n - 1) - col;
        }
        
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        
        queue<pair<int, int>> q;
        q.push({1, 0});
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        visited[1] = true;

        while(!q.empty())
        {
            int square = q.front().first;
            int steps = q.front().second;
            q.pop();

            for(int i = 1; i <= 6; i++)
            {
                int newSquare = square + i;
                
                pair<int, int> coords = squareToCords(newSquare, n);

                if (board[coords.first][coords.second] != -1)
                    newSquare = board[coords.first][coords.second];

                if (newSquare == n * n) return steps + 1;

                if (!visited[newSquare])
                {
                    q.push({newSquare, steps + 1});
                    visited[newSquare] = true;
                }

            }
        }

        return -1;
    }
};
