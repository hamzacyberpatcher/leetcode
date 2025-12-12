class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                if (grid[i][j] == 2)
                    q.push({{i, j}, 0});
        }

        int ans = 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        while(!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int minute = q.front().second; q.pop();

            ans = max(ans, minute);

            if (i + 1 < n && !visited[i + 1][j] && grid[i + 1][j] == 1)
            {
                q.push({{i + 1, j}, minute + 1});
                visited[i + 1][j] = true;
                grid[i + 1][j] = 2;
            }

            if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == 1)
            {
                q.push({{i - 1, j}, minute + 1});
                visited[i - 1][j] = true;
                grid[i - 1][j] = 2;
            }

            if (j + 1 < m && !visited[i][j + 1] && grid[i][j + 1] == 1)
            {
                q.push({{i, j + 1}, minute + 1});
                visited[i][j + 1] = true;
                grid[i][j + 1] = 2;
            }

            if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == 1)
            {
                q.push({{i, j - 1}, minute + 1});
                visited[i][j - 1] = true;
                grid[i][j - 1] = 2;
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    return -1;
        }

        return ans;
    }
};
