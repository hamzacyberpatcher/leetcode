class Solution {
public:
    struct pair_hash {
    inline size_t operator()(const std::pair<int, int> & v) const {
        // A simple way to combine hashes
        return std::hash<int>()(v.first) ^ std::hash<int>()(v.second);
    }
    };

    void DFS(int i, int j, vector<vector<int>>& heights, int pervHeight, std::unordered_set<std::pair<int, int>, pair_hash>& st)
    {
        if (st.find({i, j}) != st.end() || i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size() || heights[i][j] < pervHeight) return;

        st.insert({i, j});

        DFS(i + 1, j, heights, heights[i][j], st);
        DFS(i - 1, j, heights, heights[i][j], st);
        DFS(i, j + 1, heights, heights[i][j], st);
        DFS(i, j - 1, heights, heights[i][j], st);

        return;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        std::unordered_set<std::pair<int, int>, pair_hash> pac, atl;

        int n = heights.size();
        int m = heights[0].size();

        for(int j = 0; j < m; j++)
        {
            DFS(0, j, heights, heights[0][j], pac);
            DFS(n - 1, j, heights, heights[n - 1][j], atl);
        }

        for(int i = 0; i < n; i++)
        {
            DFS(i, 0, heights, heights[i][0], pac);
            DFS(i, m - 1, heights, heights[i][m - 1], atl);
        }

        vector<vector<int>> res;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if (pac.find({i, j}) != pac.end() && atl.find({i, j}) != atl.end())
                    res.push_back({i, j});
            }
        }

        return res;
    }
};
