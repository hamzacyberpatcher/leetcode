class Solution {
public:
    void DFS(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid, int n, int m)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] != '1')
            return;

        visited[i][j] = true;

        DFS(i - 1, j, visited, grid, n, m);
        DFS(i + 1, j, visited, grid, n, m);
        DFS(i, j - 1, visited, grid, n, m);
        DFS(i, j + 1, visited, grid, n, m);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int islands = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    DFS(i, j, visited, grid, n, m);
                    islands++;
                }
            }
        }

        return islands;
    }

};
