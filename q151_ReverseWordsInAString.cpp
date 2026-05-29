class Solution {
private:
    string trim(string s)
    {
        for(int i = 0; i < s.length() && s[i] == ' '; i++)
            s.erase(s.begin() + i);
        for(int i = s.length() - 1; i >= 0 && s[i] == ' '; i--)
            s.erase(s.begin() + i);
        
        return s;
    }
public:
    string reverseWords(string s) {
        string new_string = "";
        string temp = "";

        for(int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] != ' ') temp.append(1, s[i]);

            else if (s[i] == ' ') {
                if (temp != "")
                {
                    reverse(temp.begin(), temp.end());
                    temp.append(1, ' ');
                    new_string += temp;
                    temp = "";
                }
            }
        }

        trim(new_string);
        trim(temp);

        if (temp != "")
        {
            reverse(temp.begin(), temp.end());
            new_string += temp;
        }
        else
        {
            new_string.erase(new_string.begin() + new_string.size() - 1);
        }

        trim(new_string);

        return new_string;
    }
};
