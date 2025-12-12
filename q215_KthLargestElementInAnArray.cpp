class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;

        for(int n : nums) maxHeap.push(n);

        int res;
        for(int i = 0; i < k; i++)
        {
            res = maxHeap.top();
            maxHeap.pop();
        }

        return res;
    }
};
