/*
void printvec(const vector<int>& vec)
{
    for(int n : vec) cout << n << " ";
    cout << endl;
}
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int l = 0;
        int r = 1;

        if (size == 1) return;

        while (l < size - 1)
        {
            if (nums[l] == 0)
            {
                while(nums[r] == 0 && r < size - 1) r++;
                /*
                cout << "Before swap: " << endl;
                cout << "l: " << l << endl << "r: " << r << endl;
                printvec(nums);
                */
                swap(nums[l], nums[r]);
                /*
                cout << "After swap: " << endl;
                cout << "l: " << l << endl << "r: " << r << endl;
                printvec(nums);
                cout << endl;
                */
            }
            l++;
            r = l + 1;
        }
        
    }
};
