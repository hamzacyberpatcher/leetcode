class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        
        unordered_map<char, string> map;
        unordered_map<string, char> reverse_map;
        
        int k = 0;
        
        while (ss >> word)
        {
            
            if (k > pattern.size()) return false;
            
            char ch = pattern[k];
            
            if (map.find(ch) != map.end())
            {
                if (map[ch] != word)
                    return false;
            }
            else
            {
                if (reverse_map.find(word) != reverse_map.end())
                {
                    if (reverse_map[word] != ch)
                        return false;
                }
                
                map[ch] = word;
                reverse_map[word] = ch;
            }
            k++;
        }
        
        return k == pattern.size();
    }
};
