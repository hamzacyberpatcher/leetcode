class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> maxProfits;
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> minCapital;

        for(int i = 0; i < profits.size(); i++) minCapital.push({capital[i], profits[i]});

        for(int i = 0; i < k; i++)
        {
            while(minCapital.size() && minCapital.top().first <= w)
            {
                maxProfits.push(minCapital.top().second);
                minCapital.pop();
            }

            if (maxProfits.size())
            {
                w += maxProfits.top();
                maxProfits.pop();
            }
        }

        return w;


        return k;
    }
};
