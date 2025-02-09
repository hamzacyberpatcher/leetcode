class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        vector<int>::iterator it = nums.begin();

        for(int i = 0; i < nums.size();)
        {
            if (nums[i] == val) nums.erase(it + i);
            else i++;
        }

        return nums.size();

    }
};
