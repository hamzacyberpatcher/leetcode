class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique;
        vector<int>::iterator it = nums.begin();
        for(int i = 0; i < nums.size(); i++)
        {
            unique = nums[i];
            for(int j = i + 1; j < nums.size();)
            {
                if (nums[j] == unique) nums.erase(it + j);
                else j++;
            }
        }
        return nums.size();
    }
};
