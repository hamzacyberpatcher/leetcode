class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for(int i = 0; i < s.length(); i++)
        {
            if (map1.find(s[i]) != map1.end()) map1[s[i]]++;
            else map1.insert({s[i], 1});

            if (map2.find(t[i]) != map2.end()) map2[t[i]]++;
            else map2.insert({t[i], 1});
        }

        for(int i = 0; i < s.length(); i++)
        {
            
            
            if (map1[s[i]] != map2[s[i]])
                return false;
        }

        return true;
    }
};
