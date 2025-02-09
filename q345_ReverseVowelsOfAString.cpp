bool isVowel(char ch)
{
    switch(tolower(ch))
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

class Solution {
public:
    string reverseVowels(string s) {
        int l = 0;
        int r = s.size() - 1;

        while(l < r)
        {
            while ( l < r && !isVowel(s[l])) l++;
            while ( l < r && !isVowel(s[r])) r--;

            swap(s[l], s[r]);

            l++; r--;


        }

        return s;
    }
};
