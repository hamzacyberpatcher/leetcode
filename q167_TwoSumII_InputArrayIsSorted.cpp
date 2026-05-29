class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
     int sum;
     int l = 0;
     int r = numbers.size() - 1;
     vector<int> sol(2);

     while (l < r)
     {
        sum = numbers[l] + numbers[r];
        if (sum == target)
        {
            sol[0] = l+1;
            sol[1] = r+1;
            return sol;
        }
        else if (sum <= target) l++;
        else r--;
     }
     return sol;
    }
};
