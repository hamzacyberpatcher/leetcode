class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_elem;
        int occurence;
        int current_elem;
        int max_occurence = 0;
        int size = nums.size();
        
        for (int i = 0; i < nums.size(); i++)
        {
            current_elem = nums[i];
            occurence = 0;
            for(int j = 0; j < nums.size(); j++)
            {
                if (current_elem == maj_elem) break;
                if (nums[j] == current_elem) occurence++;
            }
            if ((occurence >= size / 2) && (occurence > max_occurence)) 
            {
                maj_elem = current_elem;
                max_occurence = occurence;
            }
        }

        return maj_elem;

    }
};
