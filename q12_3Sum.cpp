#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        vector<int> triplet;
        int size = nums.size();
        int l, r;
        int sum;

        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < size - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            l = i + 1;
            r = size - 1;
            while (l < r)
            {
                sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    triplets.push_back({nums[i],nums[l], nums[r]});

                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++; r--;
                }
                else if (sum < 0) l++;
                else r--;
            }
        }

        return triplets;

    }
};
