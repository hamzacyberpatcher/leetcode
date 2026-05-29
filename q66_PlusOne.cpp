class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;

        for(int i = digits.size() - 1; i >= 0 && carry; i--)
        {
            int digit = digits[i] + 1;

            if (digit > 9)
                digits[i] = 0;
            else
            {
                digits[i] = digit;
                carry = false;
            }
        }

        if (carry)
        {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
