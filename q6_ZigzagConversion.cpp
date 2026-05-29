class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() == 1)
            return s;

        string ret = "";
        
        int bigJump = 2 * (numRows - 1);
        
        int len = s.length();
        
        for(int i = 0; i < numRows; i++)
        {
            if (i == 0 || i == numRows - 1)
            {
                int k = i;
                
                while (k < len)
                {
                    ret += s[k];
                    k += bigJump;
                }
            }
            else
            {
                int k = i;
                int smallJump = bigJump - 2 * i;
                
                while(k < len)
                {
                    ret += s[k];
                    if (k + smallJump < len)
                        ret += s[k + smallJump];
                    k += bigJump;
                }
            }
        }
        
        
        return ret;
    }
};
