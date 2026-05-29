class Solution {
public:
    long int reverse(int x) {
        long int temp = 0;

        bool isNeg = false;
        if (x < 0 && x > INT_MIN)
        {
            isNeg = true;
            x *= -1;
        }

        while(x > 0)
        {
            temp *= 10;
            temp += x % 10;
            x /= 10;
        }

        if (temp > INT_MAX || temp < INT_MIN)
            return 0;

        if (isNeg || x < 0) return -temp;

        return temp;
    }
};
