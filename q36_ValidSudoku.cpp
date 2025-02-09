class Solution {
public:
    unordered_map<char, int> rowMap(vector<vector<char>>& board, int row)
    {
        unordered_map<char, int> map;

        for(char i = '0'; i <= '9'; i++)
            map.insert({i, 0});
        
        for(int j = 0; j < 9; j++)
            if (board[row][j] != '.')
                map[board[row][j]]++;
        
        return map;
    }

    unordered_map<char, int> colMap(vector<vector<char>>& board, int col)
    {
        unordered_map<char, int> map;

        for(char i = '0'; i <= '9'; i++)
            map.insert({i, 0});
        
        for(int i = 0; i < 9; i++)
            if(board[i][col] != '.')
                map[board[i][col]]++;
        
        return map;
    }

    unordered_map<char, int> blockMap(vector<vector<char>>& board, int r, int c)
    {
        unordered_map<char, int> map;

        for(char i = '0'; i <= '9'; i++)
            map.insert({i, 0});
        
        for(int i = r; i < r + 3; i++)
            for(int j = c; j < c + 3; j++)
                if(board[i][j] != '.')
                    map[board[i][j]]++;
        
        return map;
    }

    bool isRowValid(vector<vector<char>>& board, int r)
    {
        unordered_map<char, int> map = rowMap(board, r);

        for(const auto & p: map)
            if (p.second > 1)
                return false;
        
        return true;
    }

    bool isColValid(vector<vector<char>>& board, int c)
    {
        unordered_map<char, int> map = colMap(board, c);

        for(const auto & p: map)
            if (p.second > 1)
                return false;
        
        return true;
    }

    bool isBlockValid(vector<vector<char>>& board, int r, int c)
    {
        unordered_map<char, int> map = blockMap(board, r, c);

        for(const auto & p: map)
            if (p.second > 1)
                return false;
        
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++)
        {
            if (!isRowValid(board, i))
                return false;
            
            if (!isColValid(board, i))
                return false;
        }

        for(int i = 0; i < 9; i += 3)
            for(int j = 0; j < 9; j += 3)
                if (!isBlockValid(board, i, j))
                    return false;

        return true;
    }
};
