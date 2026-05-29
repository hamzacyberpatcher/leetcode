class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        if (st.count(beginWord)) st.erase(beginWord);

        while(!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second; q.pop();

            if (word == endWord) return steps;

            for(int i = 0; i < word.size(); i++)
            {
                char og = word[i];

                for(int j = 'a'; j <= 'z'; j++)
                {
                    word[i] = j;

                    if (st.find(word) != st.end())
                    {
                        q.push({word, steps + 1});
                        st.erase(word);
                    }
                }

                word[i] = og;
            }
        }

        return 0;
    }
};
