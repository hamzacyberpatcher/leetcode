class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l = 0;
        int r = 0;
        int sub_size = s.length();
        int string_size = t.length();

        while(l < sub_size && r < string_size)
        {
            if (s[l] == t[r]) l++;
            r++;
        }

        if (l == sub_size) return true;
        return false;
    }
};
