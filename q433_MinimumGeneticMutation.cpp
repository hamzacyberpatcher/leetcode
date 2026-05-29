class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        auto it = find(bank.begin(), bank.end(), endGene);
        if (it == bank.end()) return -1;

        int n = bank.size();
        vector<string> visited;

        queue<pair<string, int>> q;
        q.push({startGene, 0});
        visited.push_back(startGene);

        string combos = "ACGT";

        while(!q.empty())
        {
            string currGene = q.front().first;
            int level = q.front().second; q.pop();

            if (currGene == endGene) return level;

            for(int i = 0; i < currGene.size(); i++)
            {
                for(int j = 0; j < combos.size(); j++)
                {
                    string newGene = currGene;
                    newGene[i] = combos[j];

                    bool geneInVis = find(visited.begin(), visited.end(), newGene) != visited.end() ? true : false;
                    bool geneInBank = find(bank.begin(), bank.end(), newGene) != bank.end() ? true : false;

                    if (!geneInVis && geneInBank)
                    {
                        visited.push_back(newGene);
                        q.push({newGene, level + 1});
                    }
                }
            }
        }

        return -1;
    }
};
