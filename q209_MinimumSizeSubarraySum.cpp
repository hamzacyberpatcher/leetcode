class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l, r;
        l = r = 0;

        int min_size = nums.size() + 1;

        int sum = 0;

        while(r < nums.size())
        {
            sum += nums[r];

            while(sum >= target)
            {
                min_size = min(r - l + 1, min_size);
                sum -= nums[l];
                l++;
            }

            r++;
        }

        if (min_size == nums.size() + 1)
            return 0;

        return min_size;

    }
};
