class Solution {
public:
    string intToRoman(int num) {
        vector<string> neumeral = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        vector<int> vals = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

        int size = neumeral.size();

        int k = size - 1;

        string ret = "";

        while(num > 0)
        {
            if (vals[k] > num)
                k--;
            else
            {
                ret += neumeral[k];
                num -= vals[k];
            }
        }

        return ret;

        

    }
};
