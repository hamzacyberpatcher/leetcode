#include <algorithm>

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int size1 = word1.length();
        int size2 = word2.length();

        string result = "";

        int i;

        for (i = 0; i < min(size1, size2); i++)
        {
            result = result + word1[i] + word2[i];
        }


        if (size1 > size2) result += word1.substr(i, size1);
        else if (size1 < size2) result += word2.substr(i, size2);


        return result;
    }
};
