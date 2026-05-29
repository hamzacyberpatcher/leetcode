class Solution {

    int sumDigits(int n)
    {
        int sum = 0;

        while(n > 0)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }

        return sum;
    }

public:
    bool isHappy(int n) {
        unordered_map<int, bool> map;

        int sum = sumDigits(n);

        while(sum != 1)
        {
            if (map.find(sum) != map.end())     
            {
                return false;
            }

            map.insert({sum , true});

            sum = sumDigits(sum);
        }

        return true;
    }
};
