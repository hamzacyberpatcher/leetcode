#include <algorithm>

class MinStack {
    int * arr;
    int topElem;
public:
    MinStack() {
        arr = new int [300000];
        topElem = -1;
    }
    
    void push(int val) {
        topElem++;
        arr[topElem] = val;
    }
    
    void pop() {
        if (topElem == -1) return;
        else topElem--;
        return;
    }
    
    int top() {
        if (topElem != -1) return arr[topElem];
        return -1;
    }
    
    int getMin() {
        int minElem = arr[0];
        for(int n = 0; n <= topElem; n++)
        {
            minElem = min(arr[n], minElem);
        }
        return minElem;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
