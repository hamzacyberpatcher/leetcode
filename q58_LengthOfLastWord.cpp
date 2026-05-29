class Solution {
public:
    string rtrim(string s)
    {
        int len = s.length();

        if (len == 1 && s != " ") return s;
        else if (len == 1 && s == " ") return "";

        for(int i = len - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
                break;
            else
                s.erase(s.begin() + i);
        }

        return s;
    }

    int lengthOfLastWord(string s) {
        s = rtrim(s);

        int len = s.length();

        int count = 0;

        for(int i = len - 1; i >= 0; i--)
        {
            if (s[i] == ' ') break;
            count++;
        }
        
        return count;
    }
};
