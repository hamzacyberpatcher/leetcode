class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int places = 0;
        int pointer = 0;

        // Edge case: Only one spot in the flowerbed
        if (size == 1) {
            if (flowerbed[0] == 0) {
                return 1 >= n;
            } else {
                return 0 >= n;
            }
        }

        while (pointer < size) {
            if (pointer == 0) {
                // Check first spot with its neighbor
                if (flowerbed[pointer] == 0 && flowerbed[pointer + 1] == 0) {
                    places++;
                    pointer += 2;
                } else {
                    pointer++;
                }
            } else if (pointer == size - 1) {
                // Check last spot with its previous spot
                if (flowerbed[pointer] == 0 && flowerbed[pointer - 1] == 0) {
                    places++;
                    pointer++;
                } else {
                    pointer++;
                }
            } else {
                // Check middle spots with both neighbors
                if (flowerbed[pointer] == 0 && flowerbed[pointer - 1] == 0 && flowerbed[pointer + 1] == 0) {
                    places++;
                    pointer += 2;
                } else {
                    pointer++;
                }
            }
        }

        return places >= n;
    }
};
