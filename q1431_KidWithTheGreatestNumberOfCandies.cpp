#include <algorithm>

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> extra;
        int max = *max_element(candies.begin(), candies.end());
        
        for (int candy : candies)
        {
            if (candy + extraCandies >= max) extra.push_back(true);
            else extra.push_back(false);
        }

        return extra;
    }
};
