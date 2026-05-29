class Solution {
public:
    int rob(vector<int>& nums, int i, vector<int>& memo)
    {
        if (i < 0) return 0;

        if (memo[i] != -1) return memo[i];

        int skip = rob(nums, i - 1, memo);

        int robCurrent = rob(nums, i - 2, memo) + nums[i];

        memo[i] = max(skip, robCurrent);

        return memo[i];
    }

    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return rob(nums, nums.size() - 1, memo);
    }
};
