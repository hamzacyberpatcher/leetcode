class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        
        for(int i = 0; i < s.length(); i++)
        {
            if (map.find(s[i]) != map.end())
            {
                if (map[s[i]] != t[i])
                    return false;
            }
            else map.insert({s[i], t[i]});
        }

        map.clear();

        for(int i = 0; i < t.length(); i++)
        {
            if (map.find(t[i]) != map.end())
            {
                if (map[t[i]] != s[i])
                    return false;
            }
            else map.insert({t[i], s[i]});
        }

        return true;
        
    }
};
