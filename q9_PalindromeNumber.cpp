class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        unsigned int revNum = 0;

        int temp = x;

        while(temp > 0)
        {
            revNum *= 10;
            revNum += temp % 10;
            temp /= 10;
        }

        while (x > 0)
        {
            if (x % 10 != revNum % 10)
                return false;
            
            x /= 10;
            revNum /= 10;
        }

        return true;
    }
};
