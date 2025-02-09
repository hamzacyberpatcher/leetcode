class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int uni;
        vector<int>::iterator it = nums.begin();

        for(int i = 0; i < nums.size(); i++)
        {
            uni = nums[i];
            for(int j = i + 2; j < nums.size();)
            {
                if (nums[j] == uni) nums.erase(it + j);
                else j++;
            }
        }
        return nums.size();
    }
};
