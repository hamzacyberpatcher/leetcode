class Solution {
public:
    int fib(int n, vector<int>& cache)
    {
        if (n == 0 || n == 1) return 1;
        if (cache[n] != -1) return cache[n];

        cache[n - 1] = fib(n - 1, cache);
        cache[n - 2] = fib(n - 2, cache);
        
        return cache[n - 1] + cache[n - 2];
    }

    int climbStairs(int n) {
    vector<int> cache(n + 1, -1);
    return fib(n, cache);
    }
};
