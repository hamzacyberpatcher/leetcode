class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r)
        {
            while (l < r && !isalnum(s[l]) || (s[l] == ' ')) l++;
            while (l < r && !isalnum(s[r]) || (s[r] == ' ')) r--;
            if (l < r && tolower(s[l]) == tolower(s[r]))
            {
                l++;
                r--;
            }
            else if (l < r) {
                return false;
            }

        }
        return true;
    }
};
