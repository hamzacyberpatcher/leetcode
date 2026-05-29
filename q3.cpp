class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int max_length = 0;
        int left = 0;
        int n = s.size();

        for(int right = 0; right < n; right++) {
            char ch = s[right];
            if (lastSeen.find(ch) != lastSeen.end() && lastSeen[ch] >= left)
                left = lastSeen[ch] + 1;

            lastSeen[ch] = right;
            max_length = max(right - left + 1, max_length);
        }

        return max_length;
    }
};
