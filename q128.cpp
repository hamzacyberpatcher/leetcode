struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int, custom_hash> arr;
        arr.reserve(nums.size());

        for(auto n : nums) arr.insert(n);

        int maxim = 0;

        for(auto n : arr) {
            if (arr.find(n - 1) == arr.end()) {
                int x = n;
                int len = 1;

                while(arr.find(x + 1) != arr.end()) {
                    x++;
                    len++;
                }

                maxim = max(maxim, len);
            }
        }

        return maxim;
    }
};
