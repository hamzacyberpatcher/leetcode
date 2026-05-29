class Solution {
public:
    int mySqrt(int x) {

        if (x == 0) return 0;
        if (x < 1) return 1;
        if (x == 1) return 1;
        
        int left = 0;
        int right = x / 2;

        int mid = left + (right - left) / 2;

        while(left <= right)
        {
            mid = left + (right - left) / 2;

            long long squared = static_cast<long long>(mid) * mid;

            if (squared > x)
                right = mid - 1;
            else if (squared < x)
                left = mid + 1;
            else
                return mid;
        }

        return right;
    }
};
