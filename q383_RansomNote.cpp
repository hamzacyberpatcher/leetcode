class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;

        for(char i = 'a'; i <= 'z'; i++)
            map.insert({i, 0});
        
        for(const char &ch : magazine)
            map[ch]++;

        for(const char &ch : ransomNote)
        {
            if (map[ch] == 0) return false;
            else map[ch]--;
        }

        return true;
        
    }
};
