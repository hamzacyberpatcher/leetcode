class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> keys;

        for(auto s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            keys[key].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto key : keys) {
            ans.push_back(key.second);
        }

        return ans;
    }
};
