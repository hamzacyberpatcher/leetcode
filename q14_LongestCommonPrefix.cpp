class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1)
            return static_cast<string>(strs[0]);

        string prefix = "";

        int rows = strs.size();
        bool mismatch = false;

        for(int i = 0; i < strs[0].size() && !mismatch; i++)
        {
            for(int j = 0; j < rows - 1 && !mismatch; j++)
                if (strs[j][i] != strs[j + 1][i])
                    mismatch = true;
            
            if (!mismatch)
            {
                prefix += strs[0][i];
            }
        }

        return prefix;
    }
};
