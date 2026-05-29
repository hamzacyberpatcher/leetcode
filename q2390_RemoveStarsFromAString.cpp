#include <vector>

class Solution {
public:
    string removeStars(string s) {
        vector<char> meow;

        for (char ch : s)
        {
            (ch == '*') ? meow.pop_back() : meow.push_back(ch);
        }
        
        string t;

        for (char ch : meow) t += ch;

        return t;
    }
};
