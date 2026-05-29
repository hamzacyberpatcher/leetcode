#include <algorithm>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int area;
        int maxA = 0;
        int minH;

        while(l < r)
        {
            minH = min(height[l], height[r]);
            area = minH * (r - l);

            maxA = max(maxA, area);

            if (height[l] < height[r]) l++;
            else r--;
            
        }

        

        return maxA;
        
    }
};
