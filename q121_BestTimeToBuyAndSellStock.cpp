class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int l = 0;
        int r = 1;
        int maxP = 0;
        int profit;

        while (r < size)
        {
            if (prices[r] > prices[l])
            {
                profit = prices[r] - prices[l];
                if (profit > maxP) maxP = profit;
            }
            else l = r;
            r++;
        }

        return maxP;
    }
};
