class MedianFinder {
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        small.push(num);

        if (large.size() && small.top() > large.top())
        {
            int val = small.top(); small.pop();
            large.push(val);
        }

        if (small.size() > large.size() + 1)
        {
            int val = small.top(); small.pop();
            large.push(val);
        }

        if (large.size() > small.size() + 1)
        {
            int val = large.top(); large.pop();
            small.push(val);
        }
    }
    
    double findMedian() {
        if (small.size() > large.size()) return small.top();
        if (large.size() > small.size()) return large.top();

        return ((float) small.top() + (float) large.top()) / 2.f;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
